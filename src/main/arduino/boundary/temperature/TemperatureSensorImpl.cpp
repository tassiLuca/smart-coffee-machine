#include <Arduino.h>
#include "TemperatureSensorImpl.h"

// Power supply in mV
#define POWER_SUPPLY 5000
// The max value for analog read
#define MAX_INPUT_VALUE 1024.0

TemperatureSensorImpl::TemperatureSensorImpl(const int temperatureSensorPin)
    : pin(temperatureSensorPin)
{}

float TemperatureSensorImpl::getTemperature() 
{
    float mVValue = analogRead(pin) * (POWER_SUPPLY / MAX_INPUT_VALUE);
    return mVValue * 0.1;
}
