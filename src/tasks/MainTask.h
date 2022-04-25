#ifndef __MAIN_TASK__
#define __MAIN_TASK__

#include "../setup.h"
#include "Task.h"
#include "../boundary/DisplayImpl.h"

class MainTask: public Task 
{

private:
    // TODO: add peer
    Display* display;

public:
    MainTask(const int period);

};

#endif