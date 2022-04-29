#include "BaseTask.h"

BaseTask::BaseTask(const int period) : myPeriod(period) {
    elapsedTime = 0;
}

void BaseTask::init(State *state) {
    currentState = nullptr;
    stateTransition(state);
}

void BaseTask::execute() {
    currentState->handle();
};

void BaseTask::stateTransition(State *nextState) {
    if (currentState != nullptr) {
        delete currentState;
    }
    currentState = nextState;
    currentState->setTask(this);
}

bool BaseTask::updateAndCheckTime(const int basePeriod) {
    elapsedTime += basePeriod;
    if (elapsedTime >= myPeriod) {
        elapsedTime = 0;
        return true;
    } else {
        return false;
    }
}
