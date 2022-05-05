#include "ProductImpl.h"

ProductImpl::ProductImpl(const String name, const int maxQuantity)
    : quantity(maxQuantity)
    , productName(name) { }

void ProductImpl::decrementQuantity() {
    if (quantity > 0) {
        quantity -= 1;
    }
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
