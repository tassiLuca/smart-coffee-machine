#ifndef __READY_STATE__
#define __READY_STATE__

#include "../Task.h"

class ReadyState : public State {

private:
    void updateSelections();
    void dispaySelectedProduct();
    void displayReadyMessage();
    void checkTransitions();

public:
    void handle();

};

#endif