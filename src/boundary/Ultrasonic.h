#ifndef __ULTRASONIC__
#define __ULTRASONIC__

/**
 * @brief A virtual class representing an utrasonic sensor. 
 */
class Ultrasonic 
{
    
public:
    /**
     * @brief Gets the distance detected by the sensor between itself and an object. 
     * If no object is detected returns the max distance capable of measuring.
     * @return the distance measured in centimeters in the range [2, 400].
     */
    virtual float getDistance() = 0;

};

#endif