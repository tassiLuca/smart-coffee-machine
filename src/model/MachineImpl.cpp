#include "MachineImpl.h"
#include "ProductImpl.h"

#include "../setup.h"
#include "../boundary/HwCoffeeMachineFactory.h"

#define DEFAULT_SUGAR 1
#define MAX_SUGAR_LEVEL 5

MachineImpl::MachineImpl(const int productsQuantity) {
    // sensors and actuators
    CoffeeMachineFactory* f = new HwCoffeMachineFactory();
    display = f->createDisplay(DISPLAY_ROWS, DISPLAY_COLS);
    upButton = f->createButton(UP_BTN);
    downButton = f->createButton(DOWN_BTN);
    makeButton = f->createButton(MAKE_BTN);
    pot = f->createPotentiometer(POTENTIOMETER_PIN);
    // products
    products.push_back(new ProductImpl("Coffee", productsQuantity));
    products.push_back(new ProductImpl("Tea", productsQuantity));
    products.push_back(new ProductImpl("Chocolate", productsQuantity));
    selectedProduct = products.front();
    sugarLevel = DEFAULT_SUGAR;
}

void MachineImpl::displaySelections() {
    displayMessage(selectedProduct->toString() + " - " + String(sugarLevel));
}

void MachineImpl::displayMessage(String msg) {
    static String oldMsg;
    if (msg != oldMsg) {
        display->clear();
        oldMsg = msg;
    }
    display->print(msg);
}

bool MachineImpl::getAndUpdateSelectedProduct() {
    if (upButton->isPressed()) {
        auto tmp = getRefToCurrentSelectedProduct();
        selectedProduct = (*tmp == products.front() ? products.back() : *(--tmp));
        return true;
    } else if (downButton->isPressed()) {
        auto tmp = getRefToCurrentSelectedProduct();
        selectedProduct = (*tmp == products.back() ? products.front() : *(++tmp));
        return true;
    }
    return false;
}

std::list<Product*>::iterator MachineImpl::getRefToCurrentSelectedProduct() {
    std::list<Product*>::iterator product;
    for (product = products.begin(); product != products.end(); product++) {
        if ((*product) == selectedProduct) {
            return product;
        }
    }
}

bool MachineImpl::getAndUpdateSugarLevel() {
    int newSugarLevel = map(pot->getValue(), 0, 1024, DEFAULT_SUGAR, MAX_SUGAR_LEVEL + 1);
    if (sugarLevel != newSugarLevel) {
        sugarLevel = newSugarLevel;
        return true;
    }
    return false;
}

MachineState MachineImpl::getMachineState() {
    return currentState;
}

void MachineImpl::setMachineState(MachineState nextState) {
    currentState = nextState;
}

bool MachineImpl::isMaking() {
    return makeButton->isPressed() || making;
}
