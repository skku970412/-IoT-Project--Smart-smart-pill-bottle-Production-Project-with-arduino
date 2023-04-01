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
  3. Convert the information on whether the user took the medication for three types of medication (3-bit binary information) to decimal format and store it in Firebase for more efficient data organization.

- ② Pillbox Opening/Closing
  1. When it is time according to the medication information, the pillbox will open.
  2. When the user takes the medication, the pillbox will close by detecting it using an ultrasonic sensor.
    - The pillbox will be designed to close after 5 seconds of the user taking the medication.

## Development Team
| Name | Role | Univ | Dept. |
| --- | --- | --- | --- |
| Jaewook Lee | Optimize communication between boards |  SungKyunKwan University
| Jinhee Kim | Optimize communication between boards |  SungKyunKwan University
| Seungyeop Lee | Send operating signals from ultrasonic sensor to servo motor, optimize communication |  SungKyunKwan University
| Taeho Lee | Develop application for medication information input, time, and day |  SungKyunKwan University
| Yeonkyung Jang | Load time RSS information from database |  SungKyunKwan University
