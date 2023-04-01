# -IoT-Project--Smart-smart-pill-bottle-Production-Project-with-arduino
(IoT Project) Smart smart pill bottle Production Project with arduino
## 1 Development Objectives

- (Explain project motivation, goals, and detailed functionalities)
- Elderly individuals take different types of medication on different days and at different times, which can be difficult to remember every day. To solve this problem, we have developed a smart pillbox. By entering the medication administration information (days of the week when medication is administered) through an application, the pillbox will open according to the medication schedule. Once the medication is taken from the pillbox, it will close again.

## 2 Unique Features

- ◦ Current Product and Technology Status
- (Research on current similar products and technologies)
- A company called 'Gaussian' has an IoT-based pillbox that uses Bluetooth to check the medication-taking time. The application can also check the consumption and opening/closing history. The alarm is notified to the smartphone through a timer when medication is taken.
- (https://it.chosun.com/site/data/html_dir/2019/09/30/2019093001864.html)
- ◦ Differentiation from Existing Products
- (Detailed explanation of the differentiation between the existing product and the proposed product)
- 1) With the existing product, once the medication is finished, the user must refill the medication container according to the day of the week, and since the amount that can be put in at once is small, it needs to be refilled frequently. However, with the proposed product developed through this project, only the lid of the pillbox with medication for each day of the week will open, reducing the inconvenience of refilling the medication.
- 2) With the existing product, the user must enter whether they took the medication when taking it, but with the proposed product, the ultrasonic sensor can detect that the user has taken the medication without requiring additional input.
- 3) As the pillbox opens according to the medication schedule for each day of the week, the likelihood of the user taking medication for the wrong day is reduced.

## 3 Detailed Explanation of Functions

- (Implementation method and function description according to the development objectives)

### ① Application
1. Enter medication information by day of the week
2. Add Reset and Save buttons for easier information entry
3. Convert the information on whether the user took the medication for three types of medication (3-bit binary information) to decimal format and store it in Firebase for more efficient data organization

### ② Pillbox Opening/Closing
1. When it is time according to the medication information, the pillbox will open
2. When the user takes the medication, the pillbox will close by detecting it using an ultrasonic sensor
- The pillbox will be designed to close after 5 seconds of the user taking the medication

Name	Role
Jaewook Lee	Optimize communication between boards
Jinhee Kim	Optimize communication between boards
Seungyeop Lee	Send operating signals from ultrasonic sensor to servo motor, optimize communication
Taeho Lee	Develop application for medication information input, time and day
Yeonkyung Jang	Load time RSS information from database
