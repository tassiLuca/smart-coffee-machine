#ifndef __BASE_TASK__
#define __BASE_TASK__

#include "states/State.h"
#include "Task.h"

class BaseTask : public Task {

private:
    const int myPeriod;
    int elapsedTime;
    State* currentState;
    Machine* machine;
    CoffeeMachine* coffeMachineSensors;

public:
    BaseTask(const int period, Machine* machine) 
        : myPeriod(period)
        , machine(machine) 
    {
        coffeMachineSensors = new CoffeeMachine();
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

    CoffeeMachine* getSensors() {
        return coffeMachineSensors;
    }

};

#endif