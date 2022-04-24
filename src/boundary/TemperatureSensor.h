#ifndef __TEMPERATURE_SENSOR__
#define __TEMPERATURE_SENSOR__

/**
 * @brief A virtual class representing the temperature sensor. 
 */
class TemperatureSensor 
{

public:
    /**
     * @brief Reads and return the temperature value. 
     * @return the tempetature, expressed in degree Celsius.
     */
    virtual float getTemperature() = 0;
};

#endif