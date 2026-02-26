GreenSphere Ltd - Smart Solar Poultry Farming 🐓☀️
Welcome to the official repository for GreenSphere Ltd, an agritech startup based in Kigali, Rwanda. We are revolutionizing poultry farming through a climate-resilient, solar-powered system integrated with IoT and Web3/Blockchain technology for full traceability.
🚀 The Prototype
This repository contains the source code for our Smart Coop IoT Controller.
Based on our architectural diagrams, our system utilizes an ESP32 Controller to monitor and automate the poultry environment.
🔌 Hardware Components:
Microcontroller: ESP32
Sensors: DHT22 (Temperature & Humidity), Water Flow Sensor, Feed Fill Sensor
Actuators: Exhaust Fan, Red Warning Light, Buzzer Alarm, Feed Motor Dispenser
Power: 12V Solar Panel System with MPPT Charge Controller & Inverter
💻 How the Code Works:
The SmartCoop_IoT_Controller.ino code continuously reads environmental data.
Climate Control: If the temperature exceeds 30°C, the ESP32 automatically triggers a relay to turn on the Exhaust Fan, flashes the Red Warning Light, and sounds the Buzzer Alarm to protect the broilers.
Resource Monitoring: It tracks water flow using interrupts and controls the semi-automatic gravity feeder.
Blockchain Integration (WIP): This IoT data will act as an oracle, feeding transparent, immutable health and environmental data directly into our smart contracts to guarantee food safety and traceability.
📄 License
This project is licensed under the MIT License - meaning it is fully Open Source. We believe in building Digital Public Goods (DPGs) to empower youth and women smallholder farmers across Africa.
