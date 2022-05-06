#include "MainTask.h"
#include "InitState.h"

MainTask::MainTask(const int period, Machine* machine) 
    : BaseTask(period, machine) 
{
    this->init(new InitState());
}
