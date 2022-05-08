#ifndef __MACHINE_IMPL__
#define __MACHINE_IMPL__

#include <ArduinoSTL.h>
#include <list>
#include "Machine.h"
#include "../boundary/CoffeeMachineFactory.h"

#define DEFAULT_SUGAR 1
#define MAX_SUGAR_LEVEL 5

class MachineImpl : public Machine 
{

private:
    // variables
    int productsCapacity;
    Product* selectedProduct;
    std::list<Product*> products;
    int sugarLevel = DEFAULT_SUGAR;
    int selfTests = 0;
    bool making = false;
    bool testing = false;
    MachineState currentState = READY;
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
    bool moveServo(const int speed, const String startMsg="", const String endMsg="");

public:
    MachineImpl(const int productsQuantity);
    bool updateSugarLevel() override;
    bool updateSelectedProduct() override;
    bool productsAvailable() override;
    void refill() override;
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
    String getInfos() override;

};

#endif