#ifndef __MACHINE__
#define __MACHINE__

#include "Product.h"

class Machine 
{

public:
    virtual Product* getSelectedProduct() = 0;
    virtual void selectProduct(Product* product) = 0;
    virtual void getAndUpdateSugarLevel() = 0;
    virtual bool getAndUpdateSelectedProduct() = 0;
    virtual void displayMessage(String msg) = 0;

};

#endif