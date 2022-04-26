#ifndef __MAIN_TASK__
#define __MAIN_TASK__

#include "../setup.h"
#include "BaseTask.h"
#include "../boundary/DisplayImpl.h"

class MainTask: public BaseTask 
{

private:
    // TODO: add peer
    Display* display;

public:
    MainTask(const int period);

};

#endif