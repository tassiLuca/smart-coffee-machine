#include <Arduino.h>

#include "scheduler/Scheduler.h"
#include "tasks/MainTask.h"
#include "tasks/DispensingTask.h"
#include "model/MachineImpl.h"

Scheduler* scheduler;
Machine* machine;

void setup() {
    Serial.begin(9600); // TODO
    machine = new MachineImpl(10);
    scheduler = new Scheduler(50);
    // Creates all the tasks
    Task* t = new MainTask(100, machine);
    Task* t2 = new DispensingTask(100, machine);
    scheduler->addTask(t);
    scheduler->addTask(t2);
}

void loop() {
    scheduler->schedule();
}