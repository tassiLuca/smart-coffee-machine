#ifndef __PRODUCT_IMPL__
#define __PRODUCT_IMPL__

#include "Product.h"

class ProductImpl : public Product {

private:
    int quantity;
    String productName;

public:
    ProductImpl(const String name, const int maxQuantity);
    void decrementQuantity();
    int getLeftQuantity();
    bool isAvailable();
    String toString();

};

#endif