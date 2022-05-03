#include "SelfTestingTask.h"
#include "states/NormalState.h"

SelfTestingTask::SelfTestingTask(const int period, Machine* machine) 
    : BaseTask(period, machine) 
{
    this->init(new NormalState());
}