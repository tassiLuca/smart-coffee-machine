#include <Arduino.h>
#include "MainTask.h"
#include "states/InitState.h"

MainTask::MainTask(const int period, Machine* machine) 
    : BaseTask(period, machine) 
{
    MainTask::init(new InitState());
}
