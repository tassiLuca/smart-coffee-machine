#include "CoffeeMachine.h"

#include "setup.h"
#include "HwCoffeeMachineFactory.h"

CoffeeMachine::CoffeeMachine() {
    factory = new HwCoffeMachineFactory();
    upButton = factory->createButton(UP_BTN);
    downButton = factory->createButton(DOWN_BTN);
    potentiometer = factory->createPotentiometer(POTENTIOMETER_PIN);
    display = factory->createDisplay(DISPLAY_ROWS, DISPLAY_COLS);
    servoMotor = factory->createServoMotor(SERVO_MOTOR_PIN);
    ultrasonic = factory->createUltrasonic(SONAR_TRIGGER_PIN, SONAR_ECHO_PIN);
}

Button* CoffeeMachine::getUpButton() { return upButton; }

Button* CoffeeMachine::getDownButton() { return upButton; }

Button* CoffeeMachine::getMakeButton() { return makeButton; }

Potentiometer* CoffeeMachine::getPotentiometer() { return potentiometer; };

Display* CoffeeMachine::getDisplay() { return display; };

ServoMotor* CoffeeMachine::getServoMotor() { return servoMotor; };

TemperatureSensor* CoffeeMachine::getTemperatureSensor() {return temperatureSensor; }

Ultrasonic* CoffeeMachine::getUltrasonic() {return ultrasonic; };
