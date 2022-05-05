#include "DispensingTask.h"
#include "states/IdleState.h"

DispensingTask::DispensingTask(const int period, Machine* machine) 
    : BaseTask(period, machine)
{
    this->init(new IdleState());
}