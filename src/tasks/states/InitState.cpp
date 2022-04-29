#include <Arduino.h>
#include "InitState.h"
#include "ReadyState.h"

#define STATE_DURATION 3000

void InitState::handle() {
    static unsigned long enteredTime = 0;
    boundary->getDisplay()->print("Welcome");
    if (millis() - enteredTime > STATE_DURATION) {
        getTask()->stateTransition(new ReadyState());
    }
}