#ifndef __PRODUCT_IMPL__
#define __PRODUCT_IMPL__

#include "Product.h"

class ProductImpl : public Product {

private:
    int quantity;
    String productName;

public:
    ProductImpl(const String name, const int maxQuantity);
    int getLeftQuantity() override;
    bool isAvailable() override;
    String toString() override;

};

#endif