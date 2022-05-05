#ifndef __PIR_SENSOR__
#define __PIR_SENSOR__

#include "MovementDetector.h"

class PirSensor : public MovementDetector {

private:
    int pin;

public:
    PirSensor(const int pirSensorPin);
    void calibrate();
    bool isMovementDetected();
    void attachInterruptOnDetection(void (*callback)());

};

#endif