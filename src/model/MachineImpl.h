#ifndef __MACHINE_IMPL__
#define __MACHINE_IMPL__

#include <ArduinoSTL.h>
#include <list>
#include "Machine.h"

class MachineImpl : public Machine 
{

private:
    std::list<Product*> products;
    Product* selectedProduct;
    int sugarLevel;
    Product* getPointerToCurrentSelectedProduct();

public:
    MachineImpl(const int productsQuantity);
    void selectNextProduct();
    void selectPreviousProduct();
    Product* getSelectedProduct();
    void updateSugarLevel(const int amount);
    int getSugarLevel();

};

#endif