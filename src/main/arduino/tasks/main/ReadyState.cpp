#include <Arduino.h>
#include "ReadyState.h"
#include "MakingState.h"
#include "SleepState.h"
#include "AssistanceState.h"

/**
 * @todo gestione prodotto finito - non selezionabile. 
 */

#define PRODUCT_SELECTION_DURATION 5000
#define IDLE_TIMEOUT 30000

ReadyState::ReadyState() {
    lastInteraction = millis();
}

void ReadyState::handle() {
    updateSelections();
    checkTransitions();
}

void ReadyState::checkTransitions() {
    if (millis() - lastInteraction > IDLE_TIMEOUT && 
        !getMachine()->detectingSomeone() && getMachine()->getMachineState() == READY) {
        getTask()->stateTransition(new SleepState());
    } else if (getMachine()->isMaking() && getMachine()->getMachineState() == READY) {
        getMachine()->setMachineState(DISPENSING);
        getTask()->stateTransition(new MakingState());
    } else if (getMachine()->getMachineState() == ASSISTANCE) {
        getTask()->stateTransition(new AssistanceState());
    }
}

void ReadyState::updateSelections() {
    static unsigned long lastSelectionTimestamp = 0;
    bool changedSelection = getMachine()->updateSelectedProduct();
    bool changedSugar = getMachine()->updateSugarLevel();
    if (changedSelection || changedSugar) {
        lastSelectionTimestamp = millis();
        lastInteraction = millis();
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
