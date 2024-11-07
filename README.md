# Arduino Communication Protocols

This repository contains Arduino sketches demonstrating basic communication protocols, specifically I2C and UART.

## Files

### 1. `I2C.ino`
- **Description**: This file demonstrates the use of the Inter-Integrated Circuit (I2C) protocol for communication between devices. I2C is a serial communication protocol that enables multiple "slave" devices to be controlled by a single "master" device using just two data lines.
- **Purpose**: This code is suitable for beginner users looking to implement I2C communication with Arduino.
- **Features**:
  - Sends and receives data between Arduino boards via I2C.
  - Demonstrates how to configure the Arduino as a master or a slave in an I2C setup.

### 2. 'multiple_master_multiple_slave.ino'

This Arduino sketch demonstrates a more complex I2C communication setup, involving multiple master and multiple slave devices. It illustrates how to manage communication between several Arduinos functioning as either masters or slaves on the same I2C bus. This example is suitable for users who want to explore advanced I2C configurations with multiple devices.

### 3. `UART.ino`
- **Description**: This file provides an example of Universal Asynchronous Receiver-Transmitter (UART) communication. UART is a simple, point-to-point communication protocol used for serial data exchange between two devices.
- **Purpose**: Designed for beginners to understand the basics of serial communication using UART.
- **Features**:
  - Sends and receives serial data over UART.
  - Demonstrates basic configuration for serial communication on Arduino.

## Usage

1. **Upload the Code**: Connect your Arduino to your computer and upload the respective `.ino` file.
2. **Connect Devices**: Set up the hardware as per the required communication protocol (I2C or UART).
3. **Monitor Serial Output**: Use the Serial Monitor in the Arduino IDE to observe the communication data.

## Requirements

- Arduino IDE
- At least two Arduino boards for testing inter-device communication.
