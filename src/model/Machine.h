#ifndef __MACHINE__
#define __MACHINE__

#include "Product.h"

class Machine 
{

public:
    virtual Product* getSelectedProduct() = 0;
    virtual void selectProduct(Product* product) = 0;
    // virtual void addSugar() = 0;
    // virtual void make() = 0;
    // virtual void test() = 0;
    virtual void displayMessage(String msg) = 0;

};

#endif