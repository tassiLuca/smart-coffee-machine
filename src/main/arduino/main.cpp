#include <Arduino.h>

#include "scheduler/Scheduler.h"
#include "tasks/main/MainTask.h"
#include "tasks/dispensing/DispensingTask.h"
#include "tasks/selftest/SelfTestingTask.h"
#include "model/MachineImpl.h"
#include "utils/MsgService.h"

Scheduler* scheduler;
Machine* machine;

void setup() {
    Serial.begin(9600);
    machine = new MachineImpl(2);
    scheduler = new Scheduler(50);
    MsgService.init();
    // Creates all the tasks
    Task* t = new MainTask(100, machine);
    Task* t2 = new DispensingTask(50, machine);
    Task* t3 = new SelfTestingTask(500, machine);
    scheduler->addTask(t);
    scheduler->addTask(t2);
    scheduler->addTask(t3);
}

void loop() {
    // send info
    // StaticJsonDocument<200> doc;
    // doc["status"] = machine->getMachineState();
    // MsgService.sendMsg(doc);
    // scheduling
    scheduler->schedule();
}