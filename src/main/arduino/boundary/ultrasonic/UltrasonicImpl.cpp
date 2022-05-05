#include <Arduino.h>
#include "UltrasonicImpl.h"

// The speed of the sound wave at 20°C
#define SOUND_SPEED 0.034

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
    this->generateImpulse();
    float impulseDuration = pulseIn(echoPin, HIGH);
    return impulseDuration * SOUND_SPEED / 2;
}
