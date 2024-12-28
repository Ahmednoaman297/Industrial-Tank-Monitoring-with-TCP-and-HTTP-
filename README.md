# Industrial Tank Monitoring with TCP and HTTP

## Project Overview

This project involves the development of a **reliable and efficient system** for monitoring industrial tank levels using **Arduino** (or any suitable microcontroller), **Raspberry Pi**, and sensors to measure the water level. It uses **TCP** for local communication and **HTTP** for remote monitoring.

The system provides:
1. **Real-time tank level monitoring**.
2. **Two-way communication protocols** (TCP and HTTP).
3. **Fault-tolerant communication** with retry mechanisms.
4. **Secure remote access** with HTTP authentication.

---

## Components Used
- **Arduino / Microcontroller**: Interfaces with the water level sensor and sends data to Raspberry Pi.
- **Raspberry Pi**: Hosts the web server and listens for TCP data.
- **Ultrasonic Sensor**: Measures the water level in the tank.
- **Wireshark**: For packet analysis and testing fault tolerance.
- **Flask**: Used to create an HTTP server on Raspberry Pi for remote monitoring.

---

## System Architecture

1. **Sensor Integration**: Water level sensor (e.g., ultrasonic sensor) is connected to the Arduino. The Arduino reads sensor data and sends it over a **TCP connection** to the Raspberry Pi.

2. **TCP Communication**:
   - Arduino acts as the **client** and sends sensor data to the Raspberry Pi (server) in a structured format.
   - Raspberry Pi acknowledges receipt of data and stores it for remote monitoring.

3. **HTTP Communication**:
   - Raspberry Pi hosts a **Flask web server** to expose HTTP endpoints for viewing the tank level and history.
   - Authentication mechanisms are implemented to secure the `/history` endpoint.

4. **Wireshark Analysis**: Capture and analyze TCP packets for latency, acknowledgment timing, and fault tolerance.

---

## Installation

### 1. **Hardware Setup**
- **Arduino** connected to an ultrasonic sensor.
- **Raspberry Pi** connected to the network.

### 2. **Software Setup**
Follow these steps to set up the software for both Arduino and Raspberry Pi.

### **Arduino (Client)**:
1. Install the necessary libraries:
   - `Ethernet.h`
   - `ArduinoJson.h`

2. Connect the **Ethernet Shield** (or use an Ethernet module) to the Arduino and configure the IP address.

3. Upload the following code to Arduino to send sensor data to the Raspberry Pi:
