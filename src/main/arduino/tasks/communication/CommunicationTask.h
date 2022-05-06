#ifndef __COMMUNICATION_TASK__
#define __COMMUNICATION_TASK__

#include "../BaseTask.h"

class CommunicationTask: public BaseTask 
{

public:
    CommunicationTask(const int period, Machine* machine);

};

#endif