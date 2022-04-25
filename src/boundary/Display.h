#ifndef __DISPLAY__
#define __DISPLAY__

#include <ArduinoSTL.h>

class Display 
{

public:
    virtual void print(String text) = 0;
    virtual void printOnPosition(String text, std::pair<int, int> position) = 0;
    virtual void clear() = 0;

};

#endif