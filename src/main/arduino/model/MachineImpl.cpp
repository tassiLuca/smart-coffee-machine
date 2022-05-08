#include "MachineImpl.h"
#include "ProductImpl.h"

#include <assert.h>
#include "../setup.h"
#include "../boundary/HwCoffeeMachineFactory.h"

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

void MachineImpl::displaySelections() {
    displayMessage("=>" + selectedProduct->toString() + 
        ", Sugar: " + String(sugarLevel) + "/" + String(MAX_SUGAR_LEVEL));
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

bool MachineImpl::isMaking() {
    return makeButton->isPressed() || making;
}

void MachineImpl::make() {
    static int angle = 0;
    if (angle == 0) {
        displayMessage("Making " + String(selectedProduct->toString()));
    }
    making = true;
    servoMotor->setPosition(angle++);
    if (angle == 180) {
        displayMessage("The " + String(selectedProduct->toString()) + " ready");
        angle = 0;
        making = false;
        selectedProduct->consume();
    }
}

int MachineImpl::getDistance() {
    return sonarSensor->getDistance();
}

void MachineImpl::test() {
    static int angle = 0;
    testing = true;
    servoMotor->setPosition(angle);
    angle += 5;
    if (angle == 180) {
        selfTests++;
        testing = false;
        angle = 0;
        servoMotor->setPosition(angle);
    }
}

float MachineImpl::getTemperature() {
    return temperatureSensor->getTemperature();
}

bool MachineImpl::isTesting() {
    return testing;
}

bool MachineImpl::detectingSomeone() {
    return pirSensor->isMovementDetected();
}

String MachineImpl::getInfos() {
    String infos = "{'status':" + String(currentState) + ",'tests':" + selfTests + ",'products':[{";
    std::list<Product*>::iterator product;
    for (product = products.begin(); product != products.end(); product++) {
        infos += ",'" + (*product)->toString() + "':" + (*product)->getLeftQuantity();
    }
    infos += "}]}";
    return infos;
};
