#ifndef __MACHINE__
#define __MACHINE__

#include <ArduinoJson.h>
#include "Product.h"

enum MachineState { READY, DISPENSING, ASSISTANCE, TESTING };

class Machine 
{

public:
    virtual bool getAndUpdateSugarLevel() = 0;
    virtual bool getAndUpdateSelectedProduct() = 0;
    virtual bool isMaking() = 0;
    virtual void make() = 0;
    virtual void displayMessage(String msg) = 0;
    virtual void displaySelections() = 0;
    virtual MachineState getMachineState() = 0;
    virtual void setMachineState(MachineState nextState) = 0;
    virtual int getDistance() = 0;
    virtual float getTemperature() = 0;
    virtual bool productsAvailable() = 0;
    virtual bool isTesting() = 0;
    virtual void test() = 0;
    virtual bool detectingSomeone() = 0;
    virtual JsonDocument& getInfos() = 0;

};

#endif