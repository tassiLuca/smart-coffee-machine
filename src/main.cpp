#include <Arduino.h>

#include "scheduler/Scheduler.h"
#include "tasks/MainTask.h"
#include "model/MachineImpl.h"

Scheduler* scheduler;
Machine* machine;

void setup() {
    Serial.begin(9600); // TODO
    machine = (new MachineImpl::Builder)->build();
    scheduler = new Scheduler(50);
    // Creates all the tasks
    Task* t = new MainTask(100, machine);
    scheduler->addTask(t);
}

void loop() {
    scheduler->schedule();
}