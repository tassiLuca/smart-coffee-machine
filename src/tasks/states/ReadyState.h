#ifndef __READY_STATE__
#define __READY_STATE__

#include "../Task.h"

class ReadyState : public State {

private:
    void updateSelections();
    void dispaySelectedProduct();
    void displayReadyMessage();
    // check interrupt T_idle

public:
    void handle();

};

#endif