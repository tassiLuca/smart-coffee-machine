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
    int selfTests = 0;
    Product* selectedProduct;
    MachineState currentState = READY;
    bool making = false;
    bool testing = false;
    StaticJsonDocument<100> doc;
    // sensors
    Display* display;
    Button* upButton;
    Button* downButton;
    Button* makeButton;
    Potentiometer* pot;
    ServoMotor* servoMotor;
    Ultrasonic* sonarSensor;
    MovementDetector* pirSensor;
    TemperatureSensor* temperatureSensor;
    // methods
    std::list<Product*>::iterator getRefToCurrentSelectedProduct();
    void moveServo();

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
    float getTemperature();
    bool detectingSomeone();
    bool productsAvailable();
    bool isTesting();
    void test();
    JsonDocument& getInfos();

};

#endif