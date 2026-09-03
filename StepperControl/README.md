# StepperControl

This project is my first practical step into writing code for controlling a stepper motor. It is meant to be a simple, beginner-friendly setup for learning how stepper motors work, how to drive them with a microcontroller, and how to wire and configure a common stepper driver.

## Overview

This project uses a microcontroller to send step and direction signals to a stepper driver, which then powers a NEMA 17 stepper motor. The main driver in this setup is the BigTreeTech TMC2209 V1.3, a widely used silent stepper motor driver that supports UART, step/direction control, and current tuning.

## Hardware Used

- Microcontroller: ESP32
- Stepper motor: NEMA 17
- Driver: BigTreeTech TMC2209 V1.3
- Power supply: Appropriate 12V/24V supply depending on motor and driver configuration
- Wiring: Jumper wires, breadboard or PCB, common ground between controller and driver

## Why This Project

This is a learning project focused on understanding:

- how a stepper motor differs from a DC motor
- how pulse signals control position and speed
- how current limiting and microstepping work
- how to connect a driver to a microcontroller safely
- how to use a simple control loop in firmware

## Wiring Notes

The TMC2209 V1.3 is typically connected in step/direction mode:

- STEP pin from the microcontroller to the TMC2209 STEP input
- DIR pin from the microcontroller to the TMC2209 DIR input
- EN pin can be connected and controlled as needed
- Motor coil outputs A1/A2 and B1/B2 to the NEMA 17 windings
- Logic ground and motor power ground must be connected appropriately
- Make sure the driver is powered from the correct voltage and the current limit is set safely

Important safety note:

- Do not power the motor coils from the microcontroller
- Never connect motor power directly to the ESP32 pins
- Check the driver datasheet and motor wiring before applying power
- Verify the current limit before running the motor, especially on a low-cost setup

## Microcontroller Definition

The microcontroller used in this project is the ESP32. It is a strong choice for this kind of project because it offers:

- built-in Wi-Fi and Bluetooth
- multiple GPIO pins for step and direction control
- enough processing power for real-time timing tasks
- easy integration with Arduino IDE or ESP-IDF

For this project, the ESP32 is used to generate the pulse train needed to move the stepper motor and to control direction and enable states.

## Driver Definition

The primary motor driver used is the BigTreeTech TMC2209 V1.3. This driver is popular in 3D printer and CNC applications because it provides:

- quiet, smooth motion
- microstepping support
- current limiting
- step/direction interface
- optional UART configuration and diagnostic features

The TMC2209 works well with NEMA 17 motors when configured properly and is a good driver for learning stepper control.

## Software Setup

### 1. Install Arduino IDE

Download and install the Arduino IDE from:

https://www.arduino.cc/en/software

### 2. Install ESP32 Board Support

In Arduino IDE:

1. Open File > Preferences
2. Add this URL to the Additional Boards Manager URLs:
   https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json
3. Go to Tools > Board > Boards Manager
4. Search for "ESP32"
5. Install the ESP32 package

### 3. Select Your Board

In Arduino IDE:

- Go to Tools > Board
- Select your ESP32 board model (for example, ESP32 Dev Module)

### 4. Select the Correct Port

- Connect the ESP32 to your computer via USB
- Go to Tools > Port
- Select the serial port assigned to the ESP32

### 5. Install Required Libraries

If your project uses libraries, install them through the Library Manager in Arduino IDE:

- AccelStepper (commonly used for smooth stepper motion control)
- TMCStepper (if using UART-based TMC2209 configuration)

You can install them by going to:

Sketch > Include Library > Manage Libraries

## Example Project Structure

```cpp
#include <Arduino.h>

const int STEP_PIN = 18;
const int DIR_PIN = 19;
const int EN_PIN = 21;

void setup() {
  pinMode(STEP_PIN, OUTPUT);
  pinMode(DIR_PIN, OUTPUT);
  pinMode(EN_PIN, OUTPUT);

  digitalWrite(EN_PIN, LOW);
  digitalWrite(DIR_PIN, HIGH);
}

void loop() {
  digitalWrite(STEP_PIN, HIGH);
  delayMicroseconds(500);
  digitalWrite(STEP_PIN, LOW);
  delayMicroseconds(500);
}
```

This simple example rotates the motor by sending a step pulse train. In a real project, you would usually add acceleration, direction control, or a position target.

## Basic Usage

1. Connect the ESP32 to the TMC2209 step and direction inputs.
2. Connect the NEMA 17 motor to the driver.
3. Power the TMC2209 with the correct motor supply.
4. Connect logic grounds between controller and driver.
5. Upload code from Arduino IDE to the ESP32.
6. Adjust current limit and microstepping settings.
7. Test slowly at first and verify the motor moves correctly.

## Current Limiting and Tuning

The TMC2209 driver requires current limiting for safe operation. The current should be set properly to avoid overheating the motor or driver.

Typical steps:

- Measure the motor coil current requirement
- Set the driver current limit according to the motor rating
- Tune the driver using the potentiometer or software configuration
- Start with a conservative value and increase gradually

## Notes for Beginners

- Start with simple motion tests before trying complex movement profiles
- Use a small delay or low speed when testing
- Double-check motor wiring before enabling power
- If the motor jitters or does not move, verify the STEP/DIR wiring and driver current setup
- Use a bench power supply if possible to safely debug the motor system

## Future Improvements

This project can be expanded with:

- acceleration and deceleration control
- closed-loop position feedback
- limit switches
- a web interface or mobile app for controlling the motor
- integration with CNC or 3D printer style movement commands

## Conclusion

StepperControl is a simple beginner project for learning how to drive a NEMA 17 stepper motor with an ESP32 and a BigTreeTech TMC2209 V1.3 driver. It is a practical foundation for building more advanced motion-control projects in the future.

## License

This project is intended for educational and personal use. If you plan to use it in a commercial or public project, check the licensing rules of any libraries, drivers, or hardware components involved.
