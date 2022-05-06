#ifndef __MACHINE__
#define __MACHINE__

#include <ArduinoJson.h>
#include "Product.h"

/**
 * @brief An enum describing the possible states in which the 
 * machine can be. 
 */
enum MachineState { 
    /** The machine is ready to start dispensing a new product */
    READY, 
    /** The machine is dispensing a new product */
    DISPENSING, 
    /** The machine in an assistance state. No products can be made */
    ASSISTANCE, 
    /** The machine is doing a self test */
    TESTING 
};

/**
 * @brief An interface modeling the smart machine, which is 
 * responsible for its hardware components. 
 */
class Machine 
{

public:
    /**
     * @brief Updates the sugar level according to the selection.
     * @return true if the sugar level has been updated, false otherwise. 
     */
    virtual bool updateSugarLevel() = 0;

    /**
     * @brief Updates the product selection.
     * @return true if the selected product has been updated, false otherwise.
     */
    virtual bool updateSelectedProduct() = 0;

    /**
     * @brief Returns if there are available products or not. 
     * @return true if at least one product is available, false if all products
     * have been out of stock. 
     */
    virtual bool productsAvailable() = 0;

    /**
     * @brief Displays the current sugar level and the current selected product.
     */
    virtual void displaySelections() = 0;

    /**
     * @brief Displays a generic message. 
     * @param msg a string representation of the message to display.
     */
    virtual void displayMessage(String msg) = 0;

    /**
     * @brief Makes the selected products. 
     */
    virtual void make() = 0;

    /**
     * @brief Returns if the machine is making a product or not. 
     * @return true if the machine is making the selected product, false otherwise.
     */
    virtual bool isMaking() = 0;   
    
    /**
     * @brief Makes a self test. 
     */
    virtual void test() = 0;

    /**
     * @brief Returns if the machine is making a self test or not.
     * @return true if the machine is making a self test, false otherwise.
     */
    virtual bool isTesting() = 0;

    /**
     * @brief Gets the distance of the nearest object to the machine.
     * @return int the distance of the nearest detected object.
     */
    virtual int getDistance() = 0;

    /**
     * @brief Gets the machine temperature.
     * @return float the temperature in degree Celsius.
     */
    virtual float getTemperature() = 0;

    /**
     * @brief Returns if someone is in near the machine. 
     * @return true if someone is near the machine, false otherwise. 
     */
    virtual bool detectingSomeone() = 0;

    /**
     * @brief Set the state of the machine. 
     * @param nextState the next state of the machine.
     */
    virtual void setMachineState(MachineState nextState) = 0;

    /**
     * @brief Gets the current machine state. 
     * @return MachineState the current machine state.
     */
    virtual MachineState getMachineState() = 0;

    /**
     * @brief Gets all the machine infos, including: its current status,
     * the number of self tests performed since the boot and the availability
     * of each product.
     * @return JsonDocument& a reference to a JsonDocument with all the the infos.
     * @see [https://arduinojson.org](ArduinoJson)
     */
    virtual JsonDocument& getInfos() = 0;

};

#endif