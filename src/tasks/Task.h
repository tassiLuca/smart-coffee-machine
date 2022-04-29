#ifndef __TASK__
#define __TASK__

#include "states/State.h"

class State;

/**
 * @brief A virtual class representing a task. 
 */
class Task {

public:

    /**
     * @brief Initialize the task state. 
     * @param state the initial state of the task
     */
    virtual void init(State* state) = 0;

    /**
     * @brief Execute the task.
     */
    virtual void execute() = 0;

    /**
     * @brief Change the current state of the task. 
     * @param nextState the pointer to the next state.
     */
    virtual void stateTransition(State* nextState) = 0;

    /**
     * @brief Updates the elapsed time and check if it's time 
     * to execute the current task, accordingly with its period. 
     * @param basePeriod the period of the scheduler
     * @return true if this task must be executed, else otherwise.
     */
    virtual bool updateAndCheckTime(const int basePeriod) = 0;
  
};

#endif