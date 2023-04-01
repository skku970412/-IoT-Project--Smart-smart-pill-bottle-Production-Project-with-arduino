#include "FirebaseESP8266.h" // 반드시 파이어베이스 라이브러리를 먼저 추가해야 합니다.
#include <ESP8266WiFi.h>
#include <NTPClient.h>
#include <WiFiUdp.h>
//와이파이 관련 설정입니다.
#define FIREBASE_HOST "iot-coding-school-default-rtdb.firebaseio.com"
#define FIREBASE_AUTH "wTj5vJbaSIiudNFfAYl2bIlB6Pr8tdWJ1TEqaJQTb"
#define WIFI_SSID "AndroidHotspot87_D7_46" // 연결 가능한 wifi의 ssid
#define WIFI_PASSWORD "88888888" // wifi 비밀번호

//작동하는 시간을 하드코딩으로 정의한 변수입니다.
int starttime = 1526;  //오후 5시 30분
String Weekday = "Tue"; // 요일

//초음파 센서 관련 변수를 지정하는 문장입니다.
int trig = D4; // 센서 송신부 핀 설정 가정
int echo = D7; // 센서 수신부 핀 설정 가정 
//LED 관련 변수를 지정하는 문장입니다.
int aLed = D6;
int bLed = D5;
int cLed = D9;
int led[3] = {aLed, bLed, cLed};

//부저센서 변수를 저장하는 문장 관련입니다.
int buzzbuzz = D8  ;

//LED를 작동하게 하는 숫자입니다.
int Acont, Bcont, Ccont;
int control[3] = {Acont, Bcont, Ccont};

int timeis_ok, distance_ok;

const long utcOffsetInSeconds = 32400; // every UTC +1.00, +3600
String Week[6] = {"Mon", "Tue", "Tue", "Wed", "Thu", "Fri"};
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "pool.ntp.org", utcOffsetInSeconds);

FirebaseData firebaseData;
FirebaseJson json;

void printResult(FirebaseData &data);

//함수를 정의한 곳입니다.

int calc_dis() {
  int duration, distance;
  digitalWrite(trig, HIGH);
  delay(10);
  digitalWrite(trig, LOW);
  duration = pulseIn(echo, HIGH);
  distance = (duration / 2) / 29.41;  // 29.41us = 0.01m / 340m/s
  return distance;
}

int led_on() {
  for (int i = 0; i < 3; i++){
    if (control[i]) {
      digitalWrite(led[i], 1);
    }
    delay(50);    // ?? 1
  }
  return 0; 
}
int led_off() {
  for (int i = 0; i < 3; i++){
    if (1) {
      digitalWrite(led[i], 0);
    }
    delay(50);    // ?? 2
  }
  return 0; 
}

void setup() // wifi 접속 과정.
{
  Serial.begin(9600);
  WiFi.mode(WIFI_STA);

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

  Serial.println();
  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("Connected with IP: ");
  Serial.println(WiFi.localIP());
  Serial.println();

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.reconnectWiFi(true);

  firebaseData.setBSSLBufferSize(1024, 1024);
  firebaseData.setResponseSize(1024);
  Firebase.setReadTimeout(firebaseData, 1000 * 60);
  Firebase.setwriteSizeLimit(firebaseData, "tiny");

  //여기서부터는 control_file 에 관해서 추가한 코드입니다.
  //초음파센서 핀을 설정하는 곳입니다.
  pinMode(trig, OUTPUT);    // OUTPUT_PULLUP?
  pinMode(echo, INPUT);     // INPUT_PULLUP?
  //LED 핀을 설정하는 곳입니다.
  pinMode(aLed, OUTPUT);
  pinMode(bLed, OUTPUT);
  pinMode(cLed, OUTPUT);
  //확인을 위한 시리얼 통신을 합니다.
  Serial.begin(9600);
  
  //부저핀을 설정합니다.
  pinMode(buzzbuzz, OUTPUT);
  
  //여기까지는 control_file에 관해 추가한 코드입니다.

}

void loop()
{
  Serial.println("///");

  timeClient.update();

  String Day = Week[timeClient.getDay()];
  int Hour = timeClient.getHours();
  int Min = timeClient.getMinutes();

  Serial.print("currentTime: ");
  Serial.print(Day);
  Serial.print(" ");
  Serial.print(Hour);
  Serial.print(":");
  Serial.println(Min);

  Firebase.setString(firebaseData, "Day:", Day);
  Firebase.setInt(firebaseData, "Hours:", Hour);
  Firebase.setInt(firebaseData, "Minutes:", Min);

  //현재시간을 확인합니다. 12:34분이면, 1234로 저장.12:34분이면, 1234로 저장.
  int currentTime = Hour * 100 + Min;

   /////////////////////////////////////////////
   
   String val;

   if (Firebase.getString(firebaseData, Weekday)){
    val = firebaseData.stringData();
   }
   int num = val.toInt();
   Serial.println(num);
   
   // 하드코딩
//   num = 1;

//  A통 B통 C통이 열리도록 명령이 떨어졌는지 확인합니다.
  switch(num) {
    case 0:
      control[0] = 0; control[1] = 0; control[2] = 0; break;
    case 1:
      control[0] = 1; control[1] = 0; control[2] = 0; break;
    case 2:
      control[0] = 0; control[1] = 1; control[2] = 0; break;
    case 3:
      control[0] = 1; control[1] = 1; control[2] = 0; break;
    case 4:
      control[0] = 0; control[1] = 0; control[2] = 1; break;
    case 5:
      control[0] = 1; control[1] = 0; control[2] = 1; break;
    case 6:
      control[0] = 0; control[1] = 1; control[2] = 1; break;
    case 7:
      control[0] = 1; control[1] = 1; control[2] = 1; break;
  }

  Serial.print("Firebase A, B, C: ");
  Serial.print(control[0]);
  Serial.print(control[1]);
  Serial.println(control[2]);

  //시간이 맞으면
  if (starttime == currentTime) {
    Serial.println("It is time");
    timeis_ok = 1;
    // 부저
    tone(buzzbuzz, 500, 200);
    delay(50);
  }
  else{
    timeis_ok = 1;
  }

  Serial.print("Detected distance : ");
  Serial.print(calc_dis());
  Serial.println("cm");

  //거리가 30 이하 
  if (calc_dis() < 30) {
    Serial.println("Subject approaching");
    distance_ok = 1;
  }
  else{
    distance_ok = 0;
  }

  //지정한 시간이 맞고 거리가 맞으면, LED를 실행합니다.
  if (timeis_ok && distance_ok) {
    Serial.println("LED ON");
    Firebase.setString(firebaseData, "Existence", "yes");
    led_on();
  }

  //close 명령이 떨어지고, 거리도 30 이상이면 LED를 끕니다.
  if (!distance_ok) {
    Serial.println("Subject leaving. LED OFF");
    Firebase.setString(firebaseData, "Existence", "No");
    led_off();
  }
  
  delay(5000);
}