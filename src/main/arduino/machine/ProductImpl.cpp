#include "ProductImpl.h"

ProductImpl::ProductImpl(const String name, const int maxQuantity)
    : quantity(maxQuantity)
    , productName(name) { }

void ProductImpl::consume() {
    if (quantity > 0) {
        quantity -= 1;
    }
}

void ProductImpl::refill(const int quantity) {
    this->quantity = quantity;
}

int ProductImpl::getLeftQuantity() {
    return quantity;
}

bool ProductImpl::isAvailable() {
    return quantity > 0;
}

String ProductImpl::toString() {
    return productName;
}
