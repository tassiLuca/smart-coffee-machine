#include <Arduino.h>
#include "UltrasonicImpl.h"

UltrasonicImpl::UltrasonicImpl(const int triggerPin, const int echoPin)
    : triggerPin(triggerPin)
    , echoPin(echoPin) 
{
    pinMode(echoPin, INPUT);
    pinMode(triggerPin, OUTPUT);
}

void UltrasonicImpl::generateImpulse() 
{
    digitalWrite(triggerPin, LOW);
    delayMicroseconds(3);
    digitalWrite(triggerPin, HIGH);
    delayMicroseconds(5);
    digitalWrite(triggerPin, LOW);
}

float UltrasonicImpl::getDistance() 
{
    static float soundSpeed = 331.45 + 0.62 * 20;   // 20°C
    this->generateImpulse();
    float tUS = pulseIn(echoPin, HIGH);
    float t = tUS / 1000.0 / 1000.0 / 2;
    float d = t * soundSpeed;
    return d;
}
