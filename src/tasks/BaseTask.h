#ifndef __BASE_TASK__
#define __BASE_TASK__

#include "Task.h"

class BaseTask : public Task {

private:
    const int myPeriod;
    int elapsedTime;
    State* currentState;
    Machine* machine;

public:
    BaseTask(const int period, Machine* machine) 
        : myPeriod(period)
        , machine(machine) 
    {
        elapsedTime = 0;
    }

    void init(State *state) {
        currentState = nullptr;
        stateTransition(state);
    }

    virtual void execute() {
        currentState->handle();
    };

    void stateTransition(State *nextState) {
        if (currentState != nullptr) {
            delete currentState;
        }
        currentState = nextState;
        currentState->setTask(this);
    }
    
    bool updateAndCheckTime(const int basePeriod) {
        elapsedTime += basePeriod;
        if (elapsedTime >= myPeriod) {
            elapsedTime = 0;
            return true;
        } else {
            return false;
        }
    }

    Machine* getMachine() {
        return machine;
    }

};

#endif