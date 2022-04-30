#ifndef __COFFEE_MACHINE_FACTORY__
#define __COFFEE_MACHINE_FACTORY__

#include "button/Button.h"
#include "potentiometer/Potentiometer.h"
#include "display/Display.h"
#include "servo/ServoMotor.h"
#include "temperature/TemperatureSensor.h"
#include "ultrasonic/Ultrasonic.h"

/**
 * @brief The abstract factory interface which exposes methods 
 * for creating and returning different abstract products. 
 */
class CoffeeMachineFactory {

public:
    
    /**
     * @brief Creates a new button object. 
     * @param buttonPin the pin physically attached to the button.
     * @return Button* a pointer to the button.
     */
    virtual Button* createButton(const int buttonPin) const = 0;

    /**
     * @brief Creates a new potentiometer object. 
     * @param potentiometerPin the pin physically attached to the potentiometer.
     * @return Potentiometer* a pointer to the new potentiometer.
     */
    virtual Potentiometer* createPotentiometer(const int potentiometerPin) const = 0;

    /**
     * @brief Creates a new display object with `rows` rows and `cols` columns.
     * @param rows the number of rows in the display
     * @param cols the number of columns in the display
     * @return Display* a pointer to the new display.
     */
    virtual Display* createDisplay(const int rows, const int cols) const = 0;

    /**
     * @brief Creates a new servo motor object.
     * @param servoMotorPin the pin physically attached to the servo motor.
     * @return ServoMotor* a pointer to the new servo motor.
     */
    virtual ServoMotor* createServoMotor(const int servoMotorPin) const = 0;

    /**
     * @brief Creates a new temperature sensor object.
     * @param tempSensorPin the pin physically attached to the temperature sensor.
     * @return TemperatureSensor* a pointer to the new temperature sensor.
     */
    virtual TemperatureSensor* createTemperatureSensor(const int tempSensorPin) const = 0;

    /**
     * @brief Creates a new ultrasonic object. 
     * @param triggerPin the pin phsysically attached to the trigger pin
     * @param echoPin the pin physically attached to the echo pin
     * @return Ultrasonic* a pointer to the new ultrasonic sensor.
     */
    virtual Ultrasonic* createUltrasonic(const int triggerPin, const int echoPin) const = 0;

    /**
     * @todo createPirSensor() 
     */

};

#endif