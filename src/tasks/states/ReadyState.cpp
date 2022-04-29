#include <Arduino.h>
#include "ReadyState.h"

#define PRODUCT_SELECTION_DURATION 5000
#define TIMEOUT_IDLE 20000

void ReadyState::handle() {
    // static unsigned long enteredTime = millis();
    // static unsigned long t0 = 0;
    // bool resProductSelection = this->getTask()->getMachine()->getAndUpdateSelectedProduct();
    // bool resSugarSelection = this->getTask()->getMachine()->getAndUpdateSugarLevel();
    // if (resProductSelection || resSugarSelection) {
    //     t0 = millis();
    // }
    // if (millis() - t0 < PRODUCT_SELECTION_DURATION) {
    //     dispaySelectedProduct();
    // } else {
    //     displayReadyMessage();
    // }
    // // TRANSITIONS
    // if (this->getTask()->getMachine()->isMakeSelected()) {
    //     this->getTask()->stateTransition(new MakingState());
    // } else if (millis() - enteredTime > TIMEOUT_IDLE) { //TODO peer
    //     this->getTask()->stateTransition(new SleepState());
    // }
}

void ReadyState::dispaySelectedProduct() {
    // this->getTask()->getMachine()->displaySelectedProduct();
}

void ReadyState::displayReadyMessage() {
    // this->getTask()->getMachine()->displayMessage("Ready");
}
