#include <Arduino.h>
#include "ReadyState.h"

#define PRODUCT_SELECTION_DURATION 5000

void ReadyState::handle() {
    static unsigned long t0 = 0;
    bool res = this->getTask()->getMachine()->getAndUpdateSelectedProduct();
    if (res) {
        t0 = millis();
    }
    if (millis() - t0 < PRODUCT_SELECTION_DURATION) {
        dispaySelectedProduct();
    } else {
        displayReadyMessage();
    }
}

void ReadyState::dispaySelectedProduct() {
    String msg = "Product: " + this->getTask()->getMachine()->getSelectedProduct()->toString();
    this->getTask()->getMachine()->displayMessage(msg);
}

void ReadyState::displayReadyMessage() {
    this->getTask()->getMachine()->displayMessage("Ready");
}

