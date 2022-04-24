#ifndef __TASK__
#define __TASK__

/**
 * @brief A virtual class representing a task. 
 */
class Task {

private:
    int myPeriod;
    int elapsedTime;

public:
    Task(const int period) : myPeriod(period) {
        elapsedTime = 0;
    }

    virtual void tick() = 0;
    
    virtual bool updateAndCheckTime(const int basePeriod) {
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