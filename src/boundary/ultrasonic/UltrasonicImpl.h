#ifndef __ULTRASONIC_IMPL__
#define __ULTRASONIC_IMPL__

#include "Ultrasonic.h"

class UltrasonicImpl: public Ultrasonic 
{

private:
    int triggerPin;
    int echoPin;
    void generateImpulse();

public:
    UltrasonicImpl(const int triggerPin, const int echoPin);
    float getDistance();

};

#endif