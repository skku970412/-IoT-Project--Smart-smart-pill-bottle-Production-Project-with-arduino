# Smart Pillbox



## Introduction
Elderly people often have trouble remembering which medication to take on which day and at which time. To solve this problem, we have developed a smart pillbox that can be operated through a mobile application. By entering the medication information (the day and time at which the medication should be taken) in the application, the pillbox will open automatically at the appropriate time. When the user takes the medication, the pillbox will close again. 

## Development Goals
The development goals for the Smart Pillbox are:

  1. To provide elderly people with a reliable way to remember when to take their medication
  2. To simplify the process of taking medication by automatically dispensing pills at the right time
  3. To provide an easy-to-use mobile application for inputting medication information and adjusting settings
  4. To help promote better health outcomes by ensuring that medication is taken consistently and as prescribed.

## Detailed Explanation of Functions
- ① Application
  1. Enter medication information by day of the week.
  2. Add Reset and Save buttons for easier information entry.
  3. Convert the information on whether the user took the medication for three types of medication (3-bit binary information) to decimal format and store it in Firebase. 

- ② Pillbox Opening/Closing
  1. When it is time according to the medication information, the pillbox will open.
  2. When the user takes the medication, the pillbox will close by detecting it using an ultrasonic sensor.
    - The pillbox will be designed to close after 5 seconds of the user taking the medication.
## Development Team

| Name | Role | Univ | Dept |
|------|------|------|------|
| Jaewook Lee | Optimize communication between boards | SungKyunKwan University | Department of Electrical and Electronic Engineering |
| Jinhee Kim | Optimize communication between boards | SungKyunKwan University | Department of Electrical and Electronic Engineering |
| Seungyeop Lee | Send operating signals from ultrasonic sensor to servo motor, optimize communication | SungKyunKwan University | Department of Mechanical Engineering |
| Taeho Lee | Develop application for medication information input, time, and day | SungKyunKwan University | Department of Computer Science |
| Yeonkyung Jang | Load time RSS information from database | SungKyunKwan University | Department of Electrical and Electronic Engineering |


# Smart Pillbox

## 소개

노인들은 종종 어떤 약을 언제, 언제 복용해야 하는지 기억하는 데 어려움을 겪습니다. 이러한 문제를 해결하기 위해 모바일 어플리케이션을 통해 조작할 수 있는 스마트 필박스를 개발하였습니다. 애플리케이션에 투약 정보(약을 복용해야 하는 날짜와 시간)를 입력하면 적절한 시간에 약통이 자동으로 열립니다. 사용자가 약을 복용하면 필박스가 다시 닫힙니다.

## 개발 목표

Smart Pillbox의 개발 목표는 다음과 같습니다.

1. 노인들이 약을 복용해야 할 시간을 신뢰성 있게 기억하는 방법을 제공합니다.
2. 약을 적절한 시간에 자동으로 분배하여 복용 과정을 간소화합니다.
3. 약 정보 입력 및 설정 조정을 위한 사용하기 쉬운 모바일 애플리케이션을 제공합니다.
4. 약을 일관되게 복용하도록하여 건강한 결과를 촉진합니다.

## 상세한 기능 설명

### 어플리케이션

1. 요일별 약 정보를 입력합니다.
2. 리셋 및 저장 버튼을 추가하여 정보 입력을 더 쉽게 합니다.
3. 사용자가 세 종류의 약(3비트 이진 정보)을 복용했는지 여부를 십진수 형식으로 변환하여 Firebase에 데이터 를 저장합니다.

### 필박스 개폐

1. 투약 정보에 따라 적절한 시간에 필박스가 열립니다.
2. 사용자가 약을 복용하면 초음파 센서를 이용하여 필박스가 닫힙니다.
- 사용자가 약을 복용한 후 5초 내에 필박스가 닫히도록 디자인합니다.

## 개발 팀

| 이름 | 역할 | 대학 | 학과 |
|------|------|------|------|
| 이재욱 | 보드 간 통신 최적화 | 성균관대학교 | 전기전자공학과 |
| 김진희 | 보드 간 통신 최적화 | 성균관대학교 | 전자전기공학부 |
| 이승엽 | 보드 간 통신 최적화 | 성균관대학교 | 기계공학부 |
| 이태호 | 보드 간 통신 최적화 | 성균관대학교 | 전기/전자공학부 |
| 장연경 | 시간RSS 정보 데이터베이스로 불러오기 | 성균관대학교 | 화학/고분자공학부 |



