#ifndef __SELF_TESTING_TASK__
#define __SELF_TESTING_TASK__

#include "BaseTask.h"

class SelfTestingTask : public BaseTask {

public:
    SelfTestingTask(const int period, Machine* machine);

};

#endif
