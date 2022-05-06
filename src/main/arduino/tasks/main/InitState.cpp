#include <Arduino.h>
#include "InitState.h"
#include "ReadyState.h"

#define STATE_DURATION 2000

void InitState::handle() {
    static unsigned long enteredTime = millis();
    getMachine()->displayMessage("Welcome :)");
    if (millis() - enteredTime > STATE_DURATION) {
        getTask()->stateTransition(new ReadyState());
    }
}