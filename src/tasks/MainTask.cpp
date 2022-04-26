#include <Arduino.h>
#include "MainTask.h"
#include "states/InitState.h"

MainTask::MainTask(const int period) 
    : BaseTask(period) 
{
    MainTask::init(new InitState());
    display = new DisplayImpl(DISPLAY_ROWS, DISPLAY_COLS);
}
