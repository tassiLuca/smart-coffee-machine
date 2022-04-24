#include <Arduino.h>
#include "MainTask.h"

#include "../setup.h"
#include "../boundary/TemperatureSensorImpl.h"

TemperatureSensor* temp;

MainTask::MainTask(const int period)
    : Task(period)
{
    temp = new TemperatureSensorImpl(TEMPERATURE_SENSOR_PIN);
}

void MainTask::tick() 
{
    Serial.println("Temp value " + String(temp->getTemperature()));
}