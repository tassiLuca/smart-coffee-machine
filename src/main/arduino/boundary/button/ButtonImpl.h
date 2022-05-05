#ifndef __BUTTON_IMPL__
#define __BUTTON_IMPL__

#include "Button.h"

class ButtonImpl: public Button {

private:
    int pin;
    unsigned long lastDebounceTime;

public:
    ButtonImpl(const int buttonPin);
    bool isPressed();

};

#endif