#include "MachineImpl.h"
#include "ProductImpl.h"

MachineImpl::MachineImpl(const int productsQuantity) {
    display = new DisplayImpl(DISPLAY_ROWS, DISPLAY_COLS);
    products.push_back(new ProductImpl("Coffee", productsQuantity));
    products.push_back(new ProductImpl("Tea", productsQuantity));
    products.push_back(new ProductImpl("Chocolate", productsQuantity));
    selectedProduct = products.front();
}

void MachineImpl::displayMessage(String msg) {
    display->clear();
    display->print(msg);
}

void MachineImpl::selectProduct(Product* product) {
    selectedProduct = product;
}

Product* MachineImpl::getSelectedProduct() {
    return selectedProduct;
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
