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
    StaticJsonDocument<60> doc;
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
    bool updateSugarLevel() override;
    bool updateSelectedProduct() override;
    bool productsAvailable() override;
    void displaySelections() override;
    void displayMessage(String msg) override;
    void make() override;
    bool isMaking() override;
    void test() override;
    bool isTesting() override;
    int getDistance() override;
    float getTemperature() override;
    bool detectingSomeone() override;
    void setMachineState(MachineState nextState) override;
    MachineState getMachineState() override;
    JsonDocument& getInfos() override;

};

#endif