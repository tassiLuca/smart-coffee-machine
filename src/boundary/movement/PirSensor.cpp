#include <Arduino.h>
#include "PirSensor.h"

#define CALIBRATION_TIME 20000

PirSensor::PirSensor(const int pirSensorPin) {
    pin = pirSensorPin;
}

void PirSensor::calibrate() {
    delay(CALIBRATION_TIME);
}

bool PirSensor::isMovementDetected() {
    return digitalRead(pin);
}

void PirSensor::attachInterruptOnDetection(void (*callback)()) {
    attachInterrupt(digitalPinToInterrupt(pin), callback, RISING);
}