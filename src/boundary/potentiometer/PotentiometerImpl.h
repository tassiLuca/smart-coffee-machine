#ifndef __POTENTIOMETER_IMPL__
#define __POTENTIOMETER_IMPL__

#include "Potentiometer.h"

class PotentiometerImpl: public Potentiometer {

private:
    int pin;

public:
    PotentiometerImpl(const int potentiometerPin);
    int getValue();

};

#endif