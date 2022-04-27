#include <Arduino.h>
#include "ButtonImpl.h"

ButtonImpl::ButtonImpl(const int buttonPin) : pin(buttonPin) {
    pinMode(pin, INPUT_PULLUP);
}

bool ButtonImpl::isPressed() {
    return digitalRead(pin) == LOW;
}