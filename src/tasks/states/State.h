#ifndef __STATE__
#define __STATE__

#include "../Task.h"

class Task;

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

    /**
     * @brief A virtual method which implements the logic
     * associated to the concrete state. 
     */
    virtual void handle() = 0;

};

#endif