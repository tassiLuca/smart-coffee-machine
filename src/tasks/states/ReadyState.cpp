#include <Arduino.h>
#include "ReadyState.h"

#define PRODUCT_SELECTION_DURATION 5000
#define TIMEOUT_IDLE 20000

void ReadyState::handle() {
    Serial.println("Handle ready");
    updateProductSelection();
}

void ReadyState::updateProductSelection() {
    bool upBtnState = model->getUpButton()->isPressed();
    bool downBtnState = model->getDownButton()->isPressed();
    if (upBtnState || downBtnState) {
        upBtnState ? model->selectPreviousProduct() : model->selectNextProduct();
        dispaySelectedProduct();
    } else {
        displayReadyMessage();
    }
}

void ReadyState::dispaySelectedProduct() {
    model->getDisplay()->print(model->getInfoSelection());
}

void ReadyState::displayReadyMessage() {
    model->getDisplay()->print("Ready");
}

void ReadyState::updateSugarLevel() {

}

/*
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


*/
