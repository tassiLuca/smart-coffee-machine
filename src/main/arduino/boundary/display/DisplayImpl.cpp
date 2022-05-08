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

void DisplayImpl::print(String text) {
    lcd->setCursor(0, 0);
    if (text.length() > columns) {
        lcd->print(text.substring(0, columns));
        lcd->setCursor(0, 1);
        lcd->print(text.substring(columns));
    } else {
        lcd->print(text);
    }
}

void DisplayImpl::clear() {
    lcd->clear();
};