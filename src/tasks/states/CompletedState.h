#ifndef __COMPLETED_STATE__
#define __COMPLETED_STATE__

#include "../Task.h"

class CompletedState: public State {

private:
    unsigned long enteredTime;
    bool checkTransition();

public:
    CompletedState();
    void handle();

};

#endif