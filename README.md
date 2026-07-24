# Project_Nazariya
A very basic proof of concept smart cap to provide spoken obstacle detection for the visually impaired.


## Overview

This project is one of the first Arduino projects I built completely from scratch when I was 13 years old. I recently came across it while going through old projects so I decided to clean up the code, add better comments and then finally upload it here.

It was designed as a proof of concept to explore how inexpensive electronics could be used to assist visually impaired individuals with navigation.

Three ultrasonic sensors continuously monitor the front, left, and right sides of the user. Whenever an obstacle is detected within a predefined distance range, the Arduino instructs a DFPlayer Mini module to play a pre-recorded voice message indicating the obstacle's direction.

---

## Features

- Three-direction obstacle detection
- Spoken audio feedback
- Real-time ultrasonic distance measurement
- Arduino Pro Mini based
- UART communication with DFPlayer Mini

---

## Hardware Used

- Arduino Pro Mini (or any ATmega328P based microcontroller)
- 3 × HC-SR04 Ultrasonic Sensors
- DFPlayer Mini MP3 Module
- Speaker
- MicroSD Card
- Jumper Wires
- 5V power supply or 3.7v battery

---

## Wiring Diagram

### HC-SR04 Sensors

| Sensor | Trigger | Echo |
|--------|---------|------|
| Front | A0 | A1 |
| Left | A2 | A3 |
| Right | A4 | A5 |

### DFPlayer Mini

| DFPlayer Pin | Arduino Pro Mini |
|--------------|------------------|
| VCC | 5 V (RAW works too) |
| GND | GND |
| TX | RX |
| RX | TX |

I used 1k pulldown resistors on UART beacuse the DFPlayer module was misbehaving without them due to the Arduino Pro Mini's 5V TTL logic (DFPlayer module uses 3.3V TTL logic).

### Speaker

Connect the speaker directly to the **SPK1** and **SPK2** terminals on the DFPlayer Mini.

---

## How It Works

1. Measure distance using three HC-SR04 sensors.
2. Detect obstacles within 10–50 cm.
3. Determine which direction the obstacle is located.
4. Send the corresponding command to the DFPlayer Mini.
5. Play a voice prompt informing the user.

---

## Software Dependency

| Library | Version |
|---------|---------|
| DFMiniMp3 by Makuna | **1.0.1** |

This project was developed using **DFMiniMp3 v1.0.1 by makuna**. Newer versions are NOT compatible due to API changes.

---

## Image of the project itself (very old and low quality)
<img width="4608" height="3456" alt="cap1" src="https://github.com/user-attachments/assets/1d7e8a77-5679-4b78-8208-31f3bcd70198" />

---

## License

This project is licensed under the MIT License.
