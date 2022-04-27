#ifndef __PRODUCT__
#define __PRODUCT__

#include <ArduinoSTL.h>

class Product {

public:
    virtual int getLeftQuantity() = 0;
    virtual bool isAvailable() = 0;
    virtual std::string toString() = 0;

};

#endif