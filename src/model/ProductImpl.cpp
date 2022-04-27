#include "ProductImpl.h"

ProductImpl::ProductImpl(const int maxQuantity)
    : quantity(maxQuantity) { }

int ProductImpl::getLeftQuantity() {
    return quantity;
}

bool ProductImpl::isAvailable() {
    return quantity > 0;
}
