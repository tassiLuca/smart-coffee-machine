#ifndef __MACHINE_IMPL__
#define __MACHINE_IMPL__

#include <ArduinoSTL.h>
#include <list>
#include "Machine.h"

#include "../setup.h"
#include "boundary/DisplayImpl.h"
#include "boundary/ButtonImpl.h"

class MachineImpl : public Machine 
{

private:
    MachineImpl(const int productsQuantity);
    std::list<Product*> products;
    Product* selectedProduct;
    Display* display;
    Button* upButton;
    Button* downButton;
    Button* makeButton;
    Product* getNextProduct();
    Product* getPrevProduct();

public:
    Product* getSelectedProduct();
    void selectProduct(Product* product);
    void getAndUpdateSugarLevel();
    bool getAndUpdateSelectedProduct();
    void displayMessage(String msg);

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