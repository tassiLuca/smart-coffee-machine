#ifndef __PRODUCT__
#define __PRODUCT__

#include <ArduinoSTL.h>

class Product {

public:
    virtual void decrementQuantity() = 0;
    virtual int getLeftQuantity() = 0;
    virtual bool isAvailable() = 0;
    virtual String toString() = 0;

};

#endif