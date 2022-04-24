#ifndef __ULTRASONIC__
#define __ULTRASONIC__

/**
 * @brief A virtual class representing an utrasonic sensor. 
 */
class Ultrasonic {

public:
    virtual float getDistance() = 0;

};

#endif