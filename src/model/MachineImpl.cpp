#include "MachineImpl.h"
#include "ProductImpl.h"
#include <ArduinoSTL.h>
#include <iterator>

MachineImpl::MachineImpl(const int productsQuantity) {
    // sensors and actuators
    display = new DisplayImpl(DISPLAY_ROWS, DISPLAY_COLS);
    upButton = new ButtonImpl(UP_BTN);
    downButton = new ButtonImpl(DOWN_BTN);
    makeButton = new ButtonImpl(MAKE_BTN);
    // products
    products.push_back(new ProductImpl("Coffee", productsQuantity));
    products.push_back(new ProductImpl("Tea", productsQuantity));
    products.push_back(new ProductImpl("Chocolate", productsQuantity));
    selectedProduct = products.front();
}

void MachineImpl::displayMessage(String msg) {
    static String oldMsg;
    if (msg != oldMsg) {
        display->clear();
        oldMsg = msg;
    }
    display->print(msg);
}

void MachineImpl::selectProduct(Product* product) {
    selectedProduct = product;
}

Product* MachineImpl::getSelectedProduct() {
    return selectedProduct;
}


bool MachineImpl::getAndUpdateSelectedProduct() {
    if (upButton->isPressed()) {
        Serial.println("Pushed button up");
        return true;
    } else if (downButton->isPressed()) {
        Serial.println("Pushed button down");
        return true;
    }
    return false;
}

void MachineImpl::getAndUpdateSugarLevel() {

}

/////////////////////////////////// BUILDER //////////////////////////////////////////
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
