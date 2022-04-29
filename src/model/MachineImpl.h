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
    Button* upButton;
    Button* downButton;
    Button* makeButton;
    Potentiometer* potentiometer;
    Display* display;
    ServoMotor* servoMotor;
    TemperatureSensor* temperatureSensor;
    Ultrasonic* ultrasonic;

public:
    MachineImpl(const int productsQuantity);
    void selectNextProduct() override;
    void selectPreviousProduct() override;
    void updateSugarLevel(const int amount) override;
    String getInfoSelection() override;
    Button* getUpButton();
    Button* getDownButton();
    Button* getMakeButton();
    Potentiometer* getPotentiometer();
    Display* getDisplay();
    ServoMotor* getServoMotor();
    TemperatureSensor* getTemperatureSensor();
    Ultrasonic* getUltrasonic();
};

#endif