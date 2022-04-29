#include <Arduino.h>
#include "ReadyState.h"
#include "MakingState.h"
#include "SleepState.h"
#include "AssistanceState.h"

#define PRODUCT_SELECTION_DURATION 5000
#define IDLE_TIMEOUT 60000

void ReadyState::handle() {
    getMachine()->setMachineState(READY);
    updateSelections();
    checkTransitions();
}

void ReadyState::checkTransitions() {
    static unsigned long enteredTime = millis();
    if (millis() - enteredTime > IDLE_TIMEOUT) {
        getTask()->stateTransition(new SleepState());
    } else if (getMachine()->isMaking()) {
        getTask()->stateTransition(new MakingState());
    } else if (getMachine()->getMachineState() == ASSISTANCE) {
        getTask()->stateTransition(new AssistanceState());
    }
}

void ReadyState::updateSelections() {
    static unsigned long lastSelectionTimestamp = 0;
    bool changedSelection = getMachine()->getAndUpdateSelectedProduct();
    bool changedSugar = getMachine()->getAndUpdateSugarLevel();
    if (changedSelection || changedSugar) {
        lastSelectionTimestamp = millis();
    }
    if (millis() - lastSelectionTimestamp < PRODUCT_SELECTION_DURATION) {
        dispaySelectedProduct();
    } else {
        displayReadyMessage();
    }
}

void ReadyState::dispaySelectedProduct() {
    this->getMachine()->displaySelections();
}

void ReadyState::displayReadyMessage() {
    this->getMachine()->displayMessage("Ready");
}
