#include "HwCoffeeMachineFactory.h"

#include "button/ButtonImpl.h"
#include "potentiometer/PotentiometerImpl.h"
#include "display/DisplayImpl.h"
#include "servo/ServoMotorImpl.h"
#include "temperature/TemperatureSensorImpl.h"
#include "ultrasonic/UltrasonicImpl.h"
#include "movement/PirSensor.h"

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
    auto servo = new ServoMotorImpl(servoMotorPin);
    servo->on();
    return servo;
}

TemperatureSensor* HwCoffeMachineFactory::createTemperatureSensor(const int tempSensorPin) const {
    return new TemperatureSensorImpl(tempSensorPin);
}

Ultrasonic* HwCoffeMachineFactory::createUltrasonic(const int triggerPin, const int echoPin) const {
    return new UltrasonicImpl(triggerPin, echoPin);
}

MovementDetector* HwCoffeMachineFactory::createPirSensor(const int pirSensorPin) const {
    auto pir = new PirSensor(pirSensorPin);
    pir->calibrate();
    return pir;
}
