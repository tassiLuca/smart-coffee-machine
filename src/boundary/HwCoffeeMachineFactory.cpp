#ifndef __HW_COFFEE_MACHINE_FACTORY__
#define __HW_COFFEE_MACHINE_FACTORY__

#include "CoffeeMachineFactory.h"

class HwCoffeMachineFactory : public CoffeeMachineFactory {

public:

    Button* createButton(const int buttonPin) const override;

    Potentiometer* createPotentiometer(const int potentiometerPin) const override;

    Display* createDisplay(const int rows, const int cols) const override;

    ServoMotor* createServoMotor(const int servoMotorPin) const override;

    TemperatureSensor* createTemperatureSensor(const int tempSensorPin) const override;

    Ultrasonic* createUltrasonic(const int triggerPin, const int echoPin) const override;

    /**
     * @todo createPirSensor() 
     */

};

#endif