#include <Arduino.h>

#include "scheduler/Scheduler.h"
#include "tasks/MainTask.h"

Scheduler* scheduler;

void setup() {
    Serial.begin(9600); // TODO
    scheduler = new Scheduler(50);
    // Creates all the tasks
    Task* t = new MainTask(100);
    scheduler->addTask(t);
}

void loop() {
    scheduler->schedule();
}