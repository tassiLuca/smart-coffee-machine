#ifndef __NORMAL_STATE__
#define __NORMAL_STATE__

#include "../Task.h"

class NormalState : public State {

private:
    unsigned long enteredTime;

public:
    NormalState();
    void handle();

};

#endif