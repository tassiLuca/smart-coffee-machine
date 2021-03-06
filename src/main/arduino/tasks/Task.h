#ifndef __TASK__
#define __TASK__

#include "../machine/Machine.h"

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

/**
 * @brief A virtual class declaring the contract that all 
 * concrete states must implement. 
 * @see State Pattern GoF
 */
class State 
{

private:
    Task* task;

public:

    virtual ~State() {}

    /**
     * @brief Set a backreference to the Task object.
     * @param task a pointer to the task.
     */
    void setTask(Task* task) {
        this->task = task;
    }

    /**
     * @brief Get the reference of Task object.
     * @return Task* 
     */
    Task* getTask() {
        return this->task;
    }

    Machine* getMachine() {
        return getTask()->getMachine();
    }

    /**
     * @brief A virtual method which implements the logic
     * associated to the concrete state. 
     */
    virtual void handle() = 0;

};

#endif