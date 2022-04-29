#include <Arduino.h>
#include "InitState.h"
#include "ReadyState.h"

#define STATE_DURATION 3000

void InitState::handle() {
    static unsigned long enteredTime = millis();
    this->getTask()->getSensors()->getDisplay()->print("Welcome SCM!");
    if (millis() - enteredTime > STATE_DURATION) {
        this->getTask()->stateTransition(new ReadyState());
    }
}