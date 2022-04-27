#ifndef __MACHINE_IMPL__
#define __MACHINE_IMPL__

#include <ArduinoSTL.h>
#include <list>
#include "Machine.h"

#include "../setup.h"
#include "boundary/DisplayImpl.h"

class MachineImpl : public Machine 
{

private:
    MachineImpl(const int productsQuantity);
    std::list<int> products;
    Display* display;

public:
    // Product* getSelectedProduct();
    // void selectProduct(Product* product);
    // void addSugar();
    // void make();
    // void test();

    class Builder {

    private:
        bool consumed = false;
        int productsQuantity = 100;

    public:
        Builder* initProductsQuantity(const int quantity);
        MachineImpl* build();

    };

};

#endif