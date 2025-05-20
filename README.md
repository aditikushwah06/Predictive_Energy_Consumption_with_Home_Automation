# 🏠 Home Automation with Smart Metering 💡

This project combines **home automation** with **smart energy metering** to create an efficient and intelligent system for monitoring and managing electricity consumption in real time. It enables users to remotely control appliances while visualizing live power data on the cloud.

## 🔧 Technologies Used

- **ESP8266 NodeMCU** – Microcontroller for automation and data transmission  
- **PZEM-004T V3.0** – Power and energy monitoring sensor  
- **ThingSpeak** – IoT analytics platform for real-time data visualization  
- **Relay Module** – For switching home appliances  
- **LCD Display** – To show real-time power usage locally  
- **Arduino IDE** – For firmware development  
- **MIT App Inventor** *(optional)* – Custom mobile app for control (if implemented)  

## ⚙️ Features

- 🔌 **Remote Control** of appliances via Wi-Fi  
- 📊 **Real-time Monitoring** of voltage, current, power, and energy  
- ☁️ **Cloud Upload** to ThingSpeak for live graphs and analytics  
- 🧠 **Power Usage Insights** to help reduce electricity bills  
- 📱 **Scalable** for integration with mobile apps or voice assistants

## 🚀 Getting Started

**Hardware Setup:**


Connect PZEM-004T to NodeMCU (TX/RX via software serial).

Connect relay module to control appliance power lines.

Attach LCD display to show real-time values.

Power the circuit via USB or adapter.

**Software Setup:**

Flash code using Arduino IDE (see /code folder).

Add your Wi-Fi credentials and ThingSpeak API key in the sketch.

View real-time values on ThingSpeak dashboard.
