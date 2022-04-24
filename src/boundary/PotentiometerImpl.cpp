#include <Arduino.h>
#include "PotentiometerImpl.h"

PotentiometerImpl::PotentiometerImpl(const int potentiometerPin)
    : pin(potentiometerPin)
{}

int PotentiometerImpl::getValue() {
    return analogRead(pin);
}