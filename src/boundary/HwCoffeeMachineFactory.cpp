#include "HwCoffeeMachineFactory.h"

#include "ButtonImpl.h"
#include "PotentiometerImpl.h"
#include "DisplayImpl.h"
#include "ServoMotorImpl.h"
#include "TemperatureSensorImpl.h"
#include "UltrasonicImpl.h"

Button* HwCoffeMachineFactory::createButton(const int buttonPin) const {
    return new ButtonImpl(buttonPin);
}

Potentiometer* HwCoffeMachineFactory::createPotentiometer(const int potentiometerPin) const {
    return new PotentiometerImpl(potentiometerPin);
}

Display* HwCoffeMachineFactory::createDisplay(const int rows, const int cols) const {
    return new DisplayImpl(rows, cols);
}

ServoMotor* HwCoffeMachineFactory::createServoMotor(const int servoMotorPin) const {
    return new ServoMotorImpl(servoMotorPin);
}

TemperatureSensor* HwCoffeMachineFactory::createTemperatureSensor(const int tempSensorPin) const {
    return new TemperatureSensorImpl(tempSensorPin);
}

Ultrasonic* HwCoffeMachineFactory::createUltrasonic(const int triggerPin, const int echoPin) const {
    return new UltrasonicImpl(triggerPin, echoPin);
}

/**
 * @todo createPirSensor() 
 */
