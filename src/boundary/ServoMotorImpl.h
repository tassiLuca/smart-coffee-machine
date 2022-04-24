#ifndef __SERVO_MOTOR_IMPL__
#define __SERVO_MOTOR_IMPL__

#include "ServoMotor.h"

class ServoMotorImpl: public ServoMotor {

private:
    int pin;

public:
    ServoMotorImpl(const int servoMotorPin);
    void on();
    void setPosition();
    void off();

};

#endif