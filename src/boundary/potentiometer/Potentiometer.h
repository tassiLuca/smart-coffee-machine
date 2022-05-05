#ifndef __POTENTIOMETER__
#define __POTENTIOMETER__

/**
 * @brief A virtual class representing a potentiometer. 
 */
class Potentiometer {

public:
    /**
     * @brief Reads the value of the potentiometer and return its value. 
     * @return int a value between 0 to 1024.
     */
    virtual int getValue() = 0;

};

#endif