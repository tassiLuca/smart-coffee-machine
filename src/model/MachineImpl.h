#ifndef __MACHINE_IMPL__
#define __MACHINE_IMPL__

#include <ArduinoSTL.h>
#include <list>
#include "Machine.h"
#include "../boundary/CoffeeMachineFactory.h"

class MachineImpl : public Machine 
{

private:
    // variables
    std::list<Product*> products;
    int sugarLevel;
    Product* selectedProduct;
    MachineState currentState;
    bool making = false;
    // sensors
    Display* display;
    Button* upButton;
    Button* downButton;
    Button* makeButton;
    Potentiometer* pot;
    // methods
    std::list<Product*>::iterator getRefToCurrentSelectedProduct();

public:
    MachineImpl(const int productsQuantity);
    bool getAndUpdateSugarLevel();
    bool getAndUpdateSelectedProduct();
    bool isMaking();
    void displayMessage(String msg);
    void displaySelections();
    MachineState getMachineState();
    void setMachineState(MachineState nextState);

};

#endif