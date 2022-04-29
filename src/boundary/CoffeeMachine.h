#ifndef __COFFEE_MACHINE__
#define __COFFEE_MACHINE__

#include "CoffeeMachineFactory.h"

class CoffeeMachine {

private:
    CoffeeMachineFactory* factory;
    Button* upButton;
    Button* downButton;
    Button* makeButton;
    Potentiometer* potentiometer;
    Display* display;
    ServoMotor* servoMotor;
    TemperatureSensor* temperatureSensor;
    Ultrasonic* ultrasonic;

public:
    CoffeeMachine();
    Button* getUpButton();
    Button* getDownButton();
    Button* getMakeButton();
    Potentiometer* getPotentiometer();
    Display* getDisplay();
    ServoMotor* getServoMotor();
    TemperatureSensor* getTemperatureSensor();
    Ultrasonic* getUltrasonic();

};

#endif