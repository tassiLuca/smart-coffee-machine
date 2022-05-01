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
    MachineState currentState = READY;
    bool making = false;
    // sensors
    Display* display;
    Button* upButton;
    Button* downButton;
    Button* makeButton;
    Potentiometer* pot;
    ServoMotor* servoMotor;
    Ultrasonic* sonarSensor;
    MovementDetector* pirSensor;
    // methods
    std::list<Product*>::iterator getRefToCurrentSelectedProduct();

public:
    MachineImpl(const int productsQuantity);
    bool getAndUpdateSugarLevel();
    bool getAndUpdateSelectedProduct();
    bool isMaking();
    void make();
    void displayMessage(String msg);
    void displaySelections();
    MachineState getMachineState();
    void setMachineState(MachineState nextState);
    int getDistance();
    bool detectingSomeone();
    bool productsAvailable();
    void test();

};

#endif