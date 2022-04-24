#ifndef __SCHEDULER__
#define __SCHEDULER__

#include <StandardCplusplus.h>
#include <list>
#include "../tasks/Task.h"

class Scheduler {

private:
    int basePeriod;
    int elapsedTime;
    std::list<Task*> activeTasks;

public:
    Scheduler(const int basePeriod);
    bool addTask(Task* const task);
    void schedule();

};

#endif