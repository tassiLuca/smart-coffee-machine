#include <Arduino.h>
#include <Wire.h>
#include "DisplayImpl.h"

DisplayImpl::DisplayImpl(const uint8_t rows, const uint8_t columns)
    : columns(columns)
    , rows(rows) 
{
    lcd = new LiquidCrystal_I2C(getDisplayAddress(), columns, rows);
    lcd->init();
    lcd->backlight();
}

uint8_t DisplayImpl::getDisplayAddress() 
{
    uint8_t error, address;
    Wire.begin();
    for (address = 1; address < 127; address++) {
        // The i2c_scanner uses the return value of the Wire.endTransmisstion
        // to see if a device did acknowledge to the address.
        Wire.beginTransmission(address);
        error = Wire.endTransmission();
        if (!error) {
            return address;
        }
    }
    return 0;
}

void DisplayImpl::printOnPosition(String text, std::pair<int, int> position) {
    lcd->setCursor(position.first, position.second);
    lcd->print(text);
};

void DisplayImpl::print(String text) {
    printOnPosition(text, std::pair<int, int>(0, 0));
}

void DisplayImpl::clear() {
    lcd->clear();
};