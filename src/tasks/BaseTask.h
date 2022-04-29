#ifndef __BASE_TASK__
#define __BASE_TASK__

#include "Task.h"

class BaseTask : public Task {

private:
    const int myPeriod;
    int elapsedTime;
    State* currentState;

public:
    BaseTask(const int period);
    void init(State *state);
    virtual void execute();
    void stateTransition(State *nextState);
    bool updateAndCheckTime(const int basePeriod);

};

#endif