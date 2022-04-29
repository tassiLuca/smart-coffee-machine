#include <Arduino.h>
#include "ReadyState.h"

#define PRODUCT_SELECTION_DURATION 5000

void ReadyState::handle() {
    updateSelections();
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
