#ifndef __TASK__
#define __TASK__

#include "states/State.h"

/**
 * @brief A virtual class representing a task. 
 */
class Task {

private:
    int myPeriod;
    int elapsedTime;
    State* currentState;

public:
    Task(const int period) : myPeriod(period) {
        elapsedTime = 0;
    }

    ~Task() {
        delete currentState;
    }

    void init(State *state) {
        currentState = state;
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

};

#endif