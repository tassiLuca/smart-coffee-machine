#include "MachineImpl.h"

MachineImpl::MachineImpl(const int productsQuantity) {
    display = new DisplayImpl(DISPLAY_ROWS, DISPLAY_COLS);
    // init products
}

void MachineImpl::displayMessage(String msg) {
    
    display->print(msg);
}

/////////////////////////////////// BUILDER ///////////////////////////////////////////

MachineImpl::Builder* MachineImpl::Builder::initProductsQuantity(const int quantity) {
    productsQuantity = quantity;
    return this;
}

MachineImpl* MachineImpl::Builder::build() {
    if (consumed) {
        return nullptr;
    }
    consumed = true;
    return new MachineImpl(productsQuantity);
}
