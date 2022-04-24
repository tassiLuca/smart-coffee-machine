#include <Arduino.h>
#include "setup.h"
#include "boundary/PotentiometerImpl.h"
#include "boundary/TemperatureSensorImpl.h"

Potentiometer* pot;
TemperatureSensor* temp;

void setup() {
    pot = new PotentiometerImpl(POTENTIOMETER_PIN);
    temp = new TemperatureSensorImpl(TEMPERATURE_SENSOR_PIN);
}

void loop() {
    Serial.println("POT VALUE: " + String(pot->getValue()));
    Serial.println("TEMP VALUE: " + String(temp->getValue()));
    delay(1000);
}