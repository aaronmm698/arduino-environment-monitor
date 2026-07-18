# Arduino Environmental Monitor

A beginner embedded-systems learning project built with an Arduino Uno, a DHT11 temperature/humidity sensor, and a 16x2 parallel LCD.

This project was built as a foundation for future robotics work. It demonstrates the basic embedded workflow:

**sense → process → display**

## Features

- Measures ambient temperature in Fahrenheit
- Measures relative humidity
- Displays live readings on a 16x2 LCD
- Prints readings to the Arduino Serial Monitor
- Uses a 2-second sampling interval
- Handles failed sensor reads without crashing

## Hardware

- Arduino Uno R3
- DHT11 temperature and humidity sensor
- 16x2 parallel LCD (LCD1602 / HD44780-compatible)
- 10k potentiometer for LCD contrast
- Breadboard and jumper wires

## Wiring

### DHT11

| DHT11 pin | Arduino Uno |
|---|---|
| VCC | 5V |
| GND | GND |
| DATA | Digital pin 2 |

### LCD1602

| LCD pin | Arduino Uno |
|---|---|
| VSS | GND |
| VDD | 5V |
| VO | Potentiometer wiper |
| RS | Digital pin 7 |
| RW | GND |
| E | Digital pin 6 |
| D4 | Digital pin 5 |
| D5 | Digital pin 4 |
| D6 | Digital pin 3 |
| D7 | Digital pin 2 |

> Note: Update this table if your final LCD wiring uses different pins. The `LiquidCrystal` constructor in the code must match the physical wiring exactly.

## Software

- Arduino IDE
- [Adafruit DHT Sensor Library](https://github.com/adafruit/DHT-sensor-library)
- Arduino `LiquidCrystal` library

## Running the project

1. Install the required DHT library through Arduino IDE Library Manager.
2. Connect the DHT11 and LCD according to the wiring tables.
3. Adjust the 10k potentiometer until LCD characters are visible.
4. Upload `arduino_environment_monitor.ino`.
5. Open Serial Monitor at 9600 baud.


## Lessons learned

- Interfacing a digital environmental sensor
- Using the Arduino `LiquidCrystal` library in 4-bit parallel mode
- Managing sensor timing and failed readings
- Debugging breadboard wiring, LCD contrast, serial permissions, and device communication

## Next steps

- Add LED and buzzer threshold alerts
- Add a button to switch between Fahrenheit and Celsius
- Log measurements to a computer or SD card
- Apply these sensing and actuator-control fundamentals to small robotics projects
