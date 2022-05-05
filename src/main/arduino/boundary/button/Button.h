#ifndef __BUTTON__
#define __BUTTON__

/**
 * @brief A simple virtual class representing the concept of button. 
 */
class Button {

public:
    virtual bool isPressed() = 0;

};

#endif