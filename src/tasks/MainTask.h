#ifndef __MAIN_TASK__
#define __MAIN_TASK__

#include "BaseTask.h"

class MainTask: public BaseTask 
{

public:
    MainTask(const int period, Machine* machine);

};

#endif