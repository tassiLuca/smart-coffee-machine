#include "SelfTestingTask.h"
#include "NormalState.h"

SelfTestingTask::SelfTestingTask(const int period, Machine* machine) 
    : BaseTask(period, machine) 
{
    this->init(new NormalState());
}