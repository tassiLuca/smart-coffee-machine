#ifndef __MACHINE__
#define __MACHINE__

#include "Product.h"

class Machine 
{

public:
    virtual bool getAndUpdateSugarLevel() = 0;
    virtual bool getAndUpdateSelectedProduct() = 0;
    virtual void displayMessage(String msg) = 0;
    virtual void displaySelections() = 0;

};

#endif