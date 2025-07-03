# Smart Home Automation with Smart Metering

![Project Badge](https://img.shields.io/badge/IoT-Home%20Automation-blue.svg)

---

## 📌 Project Overview

This project presents a low-cost, scalable smart home automation system integrated with real-time energy monitoring using **Arduino UNO**, **ESP8266**, and **PZEM-004T** modules. It allows users to remotely control home appliances and monitor energy usage via a custom-built Android app developed with MIT App Inventor.

The goal is to enhance comfort, reduce energy consumption, and provide wireless access and visualization of home appliance metrics.

---

## 🚀 Features

- 🔌 **Smart Appliance Control**: Control up to 2 bulbs and 2 power sockets using a smartphone app via Bluetooth.
- ⚡ **Energy Monitoring**: Real-time display of voltage, current, and power using the PZEM module and LCD interface.
- ☁️ **Cloud Integration**: Send energy data to ThingSpeak for logging and graphical analysis.
- 📱 **Mobile App Interface**: Intuitive UI created using MIT App Inventor for real-time device control.
- 🌐 **Wireless Communication**: Uses Bluetooth (HC-05) and Wi-Fi (ESP8266 NodeMCU) for connectivity.

---

## 🛠️ Hardware Used

- Arduino UNO
- ESP8266 NodeMCU (Wi-Fi Module)
- HC-05 Bluetooth Module
- PZEM-004T with Current Transformer (CT)
- 16x2 LCD with I2C
- 4-Channel Relay Module
- 5V 2A Power Adapter
- Electrical Loads (2 bulbs + 2 sockets)

---

## 💻 Software Used

- Arduino IDE (for firmware development)
- MIT App Inventor (for mobile app)
- ThingSpeak (for cloud data visualization)
- Turnitin (for plagiarism check)

---

## 📱 Mobile App

Built with **MIT App Inventor**:
- Drag-and-drop blocks interface
- Buttons to control each appliance (`A/a`, `B/b` command logic)
- Connects to HC-05 via BluetoothClient

---

## 🔧 System Architecture

- **Arduino UNO** handles appliance control logic
- **PZEM Module** collects real-time energy data
- **ESP8266** sends energy metrics to ThingSpeak
- **LCD** displays local system status
- **Mobile App** sends commands via Bluetooth

---

## 📊 Results

- Reliable remote appliance control within 10 meters via Bluetooth
- Accurate and real-time energy readings displayed on both LCD and ThingSpeak
- Stable performance under multiple load scenarios
- Easy scalability for additional appliances

---

## 📈 Future Scope

- Expand appliance control to more devices
- Include voice assistant support (e.g., Google Assistant)
- Implement remote alerts via SMS or email
- Add motion or temperature sensors for automated triggers

---

