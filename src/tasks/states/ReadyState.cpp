#include <Arduino.h>
#include "ReadyState.h"

void ReadyState::dispaySelectedProduct() {
    String msg = "Product: " + this->getTask()->getMachine()->getSelectedProduct()->toString();
    this->getTask()->getMachine()->displayMessage(msg);
}

void ReadyState::handle() {
    dispaySelectedProduct();
}
