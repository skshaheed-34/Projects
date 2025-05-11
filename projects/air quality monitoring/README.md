# 🌫️ Air Quality Monitoring System using ESP32

A real-time, sensor-driven cyber-physical system (CPS) that monitors indoor air quality and automatically responds to unsafe conditions using a fan and buzzer. Data is uploaded to ThingSpeak for live monitoring and analysis.

---

## 📌 Project Overview

This system uses the **ESP32 microcontroller** to gather air quality data via:
- **MQ2 Gas Sensor** (detects gases like CO₂, LPG, NH₃, etc.)
- **DHT11 Sensor** (measures temperature and humidity)

When thresholds are exceeded (AQI > 100 or Gas > 600), the system:
- Activates a **DC fan via PWM**
- Triggers a **buzzer alert**
- Sends all readings to **ThingSpeak** cloud every 15 seconds

The system operates in a **closed-loop** with FSM-based logic and real-time feedback, forming a practical example of a **cyber-physical system**.

---

## 🔧 Hardware Components
- ESP32 (240 MHz dual-core microcontroller)
- MQ2 Gas Sensor
- DHT11 Temperature & Humidity Sensor
- DC Fan (PWM-controlled)
- Buzzer
- 5V Power Adapter
- ThingSpeak Cloud Integration

---

## 💻 Software Tools & Libraries
- **Arduino IDE** (C/C++ based development)
- Libraries:
  - `WiFi.h`
  - `HTTPClient.h`
  - `DHT.h`
  - `MQ2.h`
- Cloud: [ThingSpeak](https://thingspeak.com/)

---

## 🚀 Features
- Real-time AQI estimation from gas sensor values
- Temperature- and gas-based fan speed control (PWM)
- Buzzer alert for unsafe air conditions
- Cloud-based data visualization (ThingSpeak)
- FSM modeling and LTL-based safety logic
- WCET analysis for timing stability

---

## 📊 Parameters Uploaded to ThingSpeak
1. Temperature (°C)
2. Humidity (%)
3. Fan PWM value
4. AQI (estimated)
5. Raw gas value

---

## 🧪 Key Metrics
| Metric               | Value           |
|----------------------|-----------------|
| Avg Execution Time   | ~191.87 ms      |
| Max Loop Time        | 244 ms          |
| Std Dev (Loop Time)  | 16.81 ms        |
| Avg Response Time    | 3–5 seconds     |
| Sensor Accuracy      | ±5% of reference|

---

## 📈 Results
- System responds automatically within 5 seconds to rising pollution.
- Maintains stable performance for over 3+ hours of continuous operation.
- Reliable cloud updates even after Wi-Fi disconnections.

---

## 🛠️ Future Improvements
- Use gas-specific sensors (e.g., MQ135, MH-Z19) for accurate AQI
- Add mobile notifications (e.g., IFTTT/Blynk)
- Introduce local web dashboard (hosted on ESP32)
- Add battery backup for portability

---

## 📂 Folder Structure


---

## 📚 License
This project is open-source for academic and educational use. Attribution is appreciated.

---

## 👥 Contributors
- **Shaheed Basha Shaik**  
- **Prasanth Rayudu**

Project for **Cyber-Physical Systems (EE 600)** – Spring 2025  
San Diego State University

