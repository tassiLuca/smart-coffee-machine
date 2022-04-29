#include "MachineImpl.h"
#include "ProductImpl.h"

#define SUGAR_LEVELS 5

MachineImpl::MachineImpl(const int productsQuantity) {
    // products
    products.push_back(new ProductImpl("Coffee", productsQuantity));
    products.push_back(new ProductImpl("Tea", productsQuantity));
    products.push_back(new ProductImpl("Chocolate", productsQuantity));
    selectedProduct = products.front();
    sugarLevel = 1;
}

Product* MachineImpl::getPointerToCurrentSelectedProduct() {
    std::list<Product*>::iterator product;
    for (product = products.begin(); product != products.end(); product++) {
        if ((*product) == selectedProduct) {
            return *product;
        }
    }
    return nullptr;
}

void MachineImpl::selectNextProduct() {
    auto tmp = getPointerToCurrentSelectedProduct();
    selectedProduct = (tmp == products.back() ? products.front() : (tmp + 1));
}

void MachineImpl::selectPreviousProduct() {
    auto tmp = getPointerToCurrentSelectedProduct();
    selectedProduct = (tmp == products.front() ? products.back() : (tmp - 1));
}

void MachineImpl::updateSugarLevel(const int amount) {
    sugarLevel += 1;
}

String MachineImpl::getInfoSelection() {
    return "Choice " + selectedProduct->toString() /*+ " Sugar: " + String(sugarLevel)*/;
}

// void MachineImpl::displayMessage(String msg) {
//     static String oldMsg;
//     if (msg != oldMsg) {
//         display->clear();
//         oldMsg = msg;
//     }
//     display->print(msg);
// }

// void MachineImpl::displaySelectedProduct() {
//     displayMessage("S: " + String(sugarLevel) + " P:" + selectedProduct->toString());
// }

// bool MachineImpl::getAndUpdateSelectedProduct() {
//     if (upButton->isPressed()) {
//         selectedProduct = getNextProduct();
//         return true;
//     } else if (downButton->isPressed()) {
//         selectedProduct = getPrevProduct();
//         return true;
//     }
//     return false;
// }

// Product* MachineImpl::getNextProduct() {
//     std::list<Product*>::iterator product;
//     for (product = products.begin(); product != products.end(); product++) {
//         if ((*product) == selectedProduct) {
//             return (*product == products.back() ? products.front() : *(++product));
//         }
//     }
//     return nullptr;
// }

// Product* MachineImpl::getPrevProduct() {
//     std::list<Product*>::iterator product;
//     for (product = products.begin(); product != products.end(); product++) {
//         if ((*product) == selectedProduct) {
//             return (*product == products.front() ? products.back() : *(--product));
//         }
//     }
//     return nullptr;
// }

// bool MachineImpl::getAndUpdateSugarLevel() {
//     int newSugarLevel = map(potentiometer->getValue(), 0, 1024, 1, SUGAR_LEVELS + 1);
//     if (sugarLevel != newSugarLevel) {
//         sugarLevel = newSugarLevel;
//         return true;
//     }
//     return false;
// }

// bool MachineImpl::isMakeSelected() {
//     if (makeButton->isPressed()) {
//         servoMotor->on();
//         return true;
//     }
//     return false;
// }

// bool MachineImpl::isMaking() {
//     return making;
// }

// void MachineImpl::make() {
//     static int i = 0;
//     making = true;
//     servoMotor->setPosition(i);
//     if (++i == 181) {
//         making = false;
//         servoMotor->off();
//     }
// }

// int MachineImpl::getTotalAmountOfProducts() {
//     int count = 0;
//     std::list<Product*>::iterator product;
//     for (product = products.begin(); product != products.end(); product++) {
//         count += (*product)->getLeftQuantity();
//     }
//     return count;
// }
