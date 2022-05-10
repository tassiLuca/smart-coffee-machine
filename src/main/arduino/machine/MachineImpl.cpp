#include "MachineImpl.h"
#include "ProductImpl.h"

#include <assert.h>
#include "../setup.h"
#include "../boundary/HwCoffeeMachineFactory.h"

#define START_DISPENSING_MSG ("Making " + String(selectedProduct->toString()))
#define STOP_DISPENSING_MSG  ("The " + String(selectedProduct->toString()) + " is ready")
#define PRODUCT_NA ("=> " + selectedProduct->toString() + " NOT AVAILABLE!")
#define SELECTED_PRODUCT_MSG \
    ("=> " + selectedProduct->toString() + ", Sugar: " + String(sugarLevel))

/* This is the interrupt handler associated to the movement detector in order to
 * awake the microcontroller when someone is nearby the machine. */
void detection() { }

MachineImpl::MachineImpl(const int productsQuantity) {
    // sensors and actuators
    CoffeeMachineFactory* f = new HwCoffeMachineFactory();
    display = f->createDisplay(DISPLAY_ROWS, DISPLAY_COLS);
    upButton = f->createButton(UP_BTN);
    downButton = f->createButton(DOWN_BTN);
    makeButton = f->createButton(MAKE_BTN);
    pot = f->createPotentiometer(POTENTIOMETER_PIN);
    servoMotor = f->createServoMotor(SERVO_MOTOR_PIN);
    sonarSensor = f->createUltrasonic(SONAR_TRIGGER_PIN, SONAR_ECHO_PIN);
    pirSensor = f->createPirSensor(PIR_SENSOR);
    pirSensor->attachInterruptOnDetection(detection);
    temperatureSensor = f->createTemperatureSensor(TEMPERATURE_SENSOR_PIN);
    // products
    productsCapacity = productsQuantity;
    products.push_back(new ProductImpl("Coffee", productsQuantity));
    products.push_back(new ProductImpl("Tea", productsQuantity));
    products.push_back(new ProductImpl("Chocolate", productsQuantity));
    selectedProduct = products.front();
}

bool MachineImpl::updateSugarLevel() {
    int newSugarLevel = map(pot->getValue(), 0, 1024, DEFAULT_SUGAR, MAX_SUGAR_LEVEL + 1);
    if (sugarLevel != newSugarLevel) {
        sugarLevel = newSugarLevel;
        return true;
    }
    return false;
}

bool MachineImpl::updateSelectedProduct() {
    auto tmp = getRefToCurrentSelectedProduct(); assert(tmp != nullptr);
    if (upButton->isPressed()) {
        selectedProduct = (*tmp == products.front() ? products.back() : *(--tmp));
        return true;
    } else if (downButton->isPressed()) {
        selectedProduct = (*tmp == products.back() ? products.front() : *(++tmp));
        return true;
    }
    return false;
}

std::list<Product*>::iterator MachineImpl::getRefToCurrentSelectedProduct() {
    std::list<Product*>::iterator product;
    for (product = products.begin(); product != products.end(); product++) {
        if ((*product) == selectedProduct) {
            return product;
        }
    }
    return nullptr;
}

bool MachineImpl::productsAvailable() {
    int totalNumOfProducts = 0;
    std::list<Product*>::iterator product;
    for (product = products.begin(); product != products.end(); product++) {
        totalNumOfProducts += (*product)->getLeftQuantity();
    }
    return totalNumOfProducts > 0;
}

void MachineImpl::refill() {
    std::list<Product*>::iterator product;
    for (product = products.begin(); product != products.end(); product++) {
        (*product)->refill(productsCapacity);
    }
}

void MachineImpl::displaySelections() {
    displayMessage(selectedProduct->isAvailable() ? SELECTED_PRODUCT_MSG : PRODUCT_NA);
}

void MachineImpl::displayMessage(String msg) {
    static String oldMsg;
    if (msg != oldMsg) {
        display->clear();
        display->print(msg);
        oldMsg = msg;
    }
}

MachineState MachineImpl::getMachineState() {
    return currentState;
}

void MachineImpl::setMachineState(MachineState nextState) {
    currentState = nextState;
}

bool MachineImpl::moveServo(const int speed, const String startMessage, const String endMessage) {
    static int angle = 0;
    if (angle == 0) { displayMessage(startMessage); }
    servoMotor->setPosition(angle);
    if (angle == 180) {
        displayMessage(endMessage);
        angle = 0;
        return true;
    } 
    angle += speed;
    return false;
}

void MachineImpl::make() {
    making = true;
    bool completed = moveServo(2, START_DISPENSING_MSG, STOP_DISPENSING_MSG);
    if (completed) {
        making = false;
        selectedProduct->consume();
    }
}

bool MachineImpl::isMaking() {
    // returns true if the button MAKE has just been pressed and the current 
    // selected product is available (the dispensing process is going to start) 
    // or the dispensing process is already in progress.
    return (makeButton->isPressed() && selectedProduct->isAvailable()) || making;
}

void MachineImpl::test() {
    testing = true;
    bool completed = moveServo(5);
    if (completed) {
        selfTests++;
        testing = false;
        resetMotorPosition();
    }
}

void MachineImpl::resetMotorPosition() {
    servoMotor->setPosition(0);
}

bool MachineImpl::isTesting() {
    return testing;
}

float MachineImpl::getTemperature() {
    return temperatureSensor->getTemperature();
}

int MachineImpl::getDistance() {
    return sonarSensor->getDistance();
}

bool MachineImpl::detectingSomeone() {
    return pirSensor->isMovementDetected();
}

String MachineImpl::getInfos() {
    String infos = "{'status':" + String(currentState) + ",'tests':" + selfTests + ",'products':{";
    std::list<Product*>::iterator product;
    for (product = products.begin(); product != products.end(); product++) {
        infos += "'" + (*product)->toString() + "':" + (*product)->getLeftQuantity() + ",";
    }
    infos.remove(infos.length() - 1);
    infos += "}}";
    return infos;
};
