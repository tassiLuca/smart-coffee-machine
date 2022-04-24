#include <iterator>

#include "Scheduler.h"

Scheduler::Scheduler(const int basePeriod): basePeriod(basePeriod) {
    this->elapsedTime = 0;
}

bool Scheduler::addTask(Task* const task) {
    this->activeTasks.push_back(task);
}

void Scheduler::schedule() {
    std::list<Task*>::iterator task;
    for (task = this->activeTasks.begin(); task != this->activeTasks.end(); task++) {
        if ((*task)->updateAndCheckTime(this->basePeriod)) {
            (*task)->tick();
        }
    }
}