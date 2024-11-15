# ❤️📊 Heart Rate and SpO2 Monitoring System using MAX30100, ESP32, and Firebase

## 🌟 Introduction
This project demonstrates a real-time system for monitoring **heart rate (bpm)** ❤️ and **blood oxygen levels (SpO2)** 🩸 using the **MAX30100 pulse oximeter sensor**, **ESP32 microcontroller**, and **Firebase Realtime Database** ☁️. The system reads health metrics, sends the data to Firebase, and allows cloud storage and visualization.
![20241115_1328391](https://github.com/user-attachments/assets/26a1d644-1900-4bfc-b6ac-618641e919bc)


## 🔧 Project Approach
1. **Sensor Integration** 🎛️:
   - The MAX30100 sensor is initialized to collect heart rate and SpO2 data.
   - A callback function detects heartbeats and updates readings.

2. **Connectivity** 📡:
   - The ESP32 is configured to connect to a Wi-Fi network.
   - Firebase is integrated for data storage.

3. **Data Transmission** 🔄:
   - Sensor readings are checked for validity.
   - Valid data is transmitted to Firebase at regular intervals (every 2 seconds).

4. **Visualization** 📈:
   - Data stored in Firebase can be visualized using Firebase's integrated dashboard or third-party analytics tools.

## 🛠️ Components Required
- 🔌 **ESP32 Dev Kit**
- 🩺 **MAX30100 Pulse Oximeter Sensor**
- 🪛 **Jumper Wires**
- ⚙️ **Breadboard**

## 📍 Pin Diagram
| **ESP32 Pin** | **MAX30100 Pin** |
|---------------|------------------|
| 3.3V          | VCC              |
| GND           | GND              |
| SDA (GPIO21)  | SDA              |
| SCL (GPIO22)  | SCL              |

## 🚀 Setup Instructions
1. **Hardware Setup** 🧩:
   - Connect the MAX30100 sensor to the ESP32 as per the pin diagram.
   - Ensure secure and proper connections.

2. **Software Setup** 💻:
   - Install the required libraries:
     - `FirebaseESP32` 🔥
     - `MAX30100_PulseOximeter` 💓
   - Update the Wi-Fi and Firebase credentials in the code.
   - Upload the code to the ESP32 using the Arduino IDE.

3. **Firebase Setup** 🔒:
   - Create a Firebase project.
   - Set up a Realtime Database and copy its URL.
   - Obtain the database secret (legacy token) for authentication.

4. **Run the System** 🏃:
   - Power the ESP32.
   - Monitor the serial output for sensor readings and Firebase updates.

## 📷 Screenshots
![20241115_1328481](https://github.com/user-attachments/assets/f9bc3093-d876-4a26-8348-8ff1644a8509)
![Screenshot 2024-11-15 1353331](https://github.com/user-attachments/assets/7486cabc-3931-4b70-b21b-e7ed835dd645)





## 🔮 Future Scope
- **Integration with Mobile Applications** 📱:
  - Create a mobile app for real-time health monitoring.
- **Advanced Analytics** 🤖:
  - Utilize machine learning to analyze trends in health data.
- **Wearable Device** ⌚:
  - Design a compact, battery-operated wearable version of the system.
- **Additional Metrics** 📋:
  - Include more sensors to track other health parameters like blood pressure.

## ✨ Key Features
- **Real-time Monitoring** ⏱️: Logs and displays SpO2 and heart rate data continuously.
- **Cloud Storage** ☁️: Data is securely stored and accessible via Firebase.
- **Scalability** 🛠️: The project can be extended to multiple users with minimal changes.

## 🧩 Challenges and Solutions
- **Sensor Initialization** ⚡:
  - Issue: MAX30100 sensor failed to initialize properly.
  - Solution: Verified wiring and ensured the library was correctly installed.
- **Firebase Integration** 🔌:
  - Issue: Data upload failed during testing.
  - Solution: Confirmed correct Firebase credentials and ensured stable Wi-Fi.
