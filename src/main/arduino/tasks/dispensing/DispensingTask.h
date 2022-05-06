#ifndef __DISPENSING_TASK__
#define __DISPENSING_TASK__

#include "../BaseTask.h"

class DispensingTask : public BaseTask {

public:
    DispensingTask(const int period, Machine* machine);

};

#endif