#ifndef __TASK__
#define __TASK__

#include "states/State.h"
#include "../model/Machine.h"

class State;

/**
 * @brief A virtual class representing a task. 
 */
class Task {

public:

    virtual void init(State* state) = 0;

    virtual void execute() = 0;

    virtual void stateTransition(State* nextState) = 0;

    virtual bool updateAndCheckTime(const int basePeriod) = 0;

    virtual Machine* getMachine() = 0;
    
};

#endif