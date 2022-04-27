#ifndef __PRODUCT_IMPL__
#define __PRODUCT_IMPL__

#include "Product.h"

class ProductImpl : public Product {

private:
    std::string name;
    int quantity;

public:
    ProductImpl(const int maxQuantity);
    int getLeftQuantity();
    bool isAvailable();
    std::string toString();

};

#endif