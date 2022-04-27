#include "ProductImpl.h"

ProductImpl::ProductImpl(const String name, const int maxQuantity)
    : quantity(maxQuantity)
    , productName(name) { }

int ProductImpl::getLeftQuantity() {
    return quantity;
}

bool ProductImpl::isAvailable() {
    return quantity > 0;
}

String ProductImpl::toString() {
    return productName;
}
