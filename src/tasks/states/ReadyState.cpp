#include <Arduino.h>
#include "ReadyState.h"

void ReadyState::dispaySelectedProduct() {
    String msg = "Product: " + this->getTask()->getMachine()->getSelectedProduct()->toString();
    this->getTask()->getMachine()->displayMessage(msg);
}

void ReadyState::handle() {
    static unsigned long t0 = 0;
    bool res = this->getTask()->getMachine()->getAndUpdateSelectedProduct();
    if (res) {
        t0 = millis();
    }
    if (millis() - t0 < 5000) {
        dispaySelectedProduct();
    } else {
        this->getTask()->getMachine()->displayMessage("READY");
    }
}
