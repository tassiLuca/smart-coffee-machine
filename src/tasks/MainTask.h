#ifndef __MAIN_TASK__
#define __MAIN_TASK__

#include "Task.h"

class MainTask: public Task {

public:
    MainTask(const int period);
    void tick();

};

#endif