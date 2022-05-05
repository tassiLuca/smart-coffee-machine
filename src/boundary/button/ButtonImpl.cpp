#include <Arduino.h>
#include "ButtonImpl.h"

#define BOUNCING_TIME 150

ButtonImpl::ButtonImpl(const int buttonPin) : pin(buttonPin) {
    pinMode(pin, INPUT_PULLUP);
    lastDebounceTime = 0;
}

bool ButtonImpl::isPressed() {
    unsigned long now = millis();
    if (digitalRead(pin) == LOW && (now - lastDebounceTime) > BOUNCING_TIME) {
        lastDebounceTime = now;
        return true;
    }
    return false;
}