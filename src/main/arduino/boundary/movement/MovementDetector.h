#ifndef __MOVEMENT_DETECTOR__
#define __MOVEMENT_DETECTOR__

class MovementDetector {

public:
    virtual bool isMovementDetected() = 0;
    virtual void calibrate() = 0;
    virtual void attachInterruptOnDetection(void (*callback)()) = 0;
};

#endif