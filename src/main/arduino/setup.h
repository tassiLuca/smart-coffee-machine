#ifndef __SETUP__
#define __SETUP__

// Button pins.
#define UP_BTN   3
#define DOWN_BTN 4
#define MAKE_BTN 5

// Sonar sensor pins.
#define SONAR_TRIGGER_PIN 8
#define SONAR_ECHO_PIN    9

// Potentiometer pin.
#define POTENTIOMETER_PIN A0

// Temperature sensor pin.
#define TEMPERATURE_SENSOR_PIN A1

// Display infos.
// Keep in mind, since we are using Arduino Uno:
// +-------------+-------------+
// + Display Pin + Arduino Pin +
// +-------------+-------------+
// +     SCL     +      A5     +
// +     SDA     +      A4     +
// +-------------+-------------+
// Refer to [https://www.arduino.cc/en/reference/wire] 
#define DISPLAY_COLS 20
#define DISPLAY_ROWS 2

// Servo motor.
#define SERVO_MOTOR_PIN 11

// Pir sensor: keep in mind this pin must support interrupts.
// Actually, all pins can support interrupt with EnableInterrupt library.
#define PIR_SENSOR 2

#endif