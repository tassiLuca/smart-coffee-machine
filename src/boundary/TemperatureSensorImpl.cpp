#include <Arduino.h>
#include "TemperatureSensorImpl.h"

#define VCC 5000
#define MAX_INPUT_VALUE 1023

TemperatureSensorImpl::TemperatureSensorImpl(const int temperatureSensorPin)
    : pin(temperatureSensorPin)
{}

int TemperatureSensorImpl::getValue() 
{
    int mVValue = VCC / MAX_INPUT_VALUE * analogRead(pin);
    return mVValue * 0.1;
}
