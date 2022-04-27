#include "MachineImpl.h"
#include "ProductImpl.h"

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
        Serial.println("UP PRESSED");
        selectedProduct = getNextProduct();
        return true;
    } else if (downButton->isPressed()) {
        Serial.println("DOWN PRESSED");
        selectedProduct = getPrevProduct();
        return true;
    }
    return false;
}

Product* MachineImpl::getNextProduct() {
    std::list<Product*>::iterator product;
    for (product = products.begin(); product != products.end(); product++) {
        if ((*product) == selectedProduct) {
            return (*product == products.back() ? products.front() : *(++product));
        }
    }
    return nullptr;
}

Product* MachineImpl::getPrevProduct() {
    std::list<Product*>::iterator product;
    for (product = products.begin(); product != products.end(); product++) {
        if ((*product) == selectedProduct) {
            return (*product == products.front() ? products.back() : *(--product));
        }
    }
    return nullptr;
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
