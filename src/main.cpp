#include <Arduino.h>
#include "scheduler/Scheduler.h"
#include "tasks/MainTask.h"

Scheduler* scheduler;

void setup() {
    scheduler = new Scheduler(500);
    Task* t = new MainTask(1000);
    scheduler->addTask(t);
}

void loop() {
    scheduler->schedule();
}