#ifndef __READY_STATE__
#define __READY_STATE__

#include "State.h"

class ReadyState : public State {

private:
    void dispaySelectedProduct();
    void displayReadyMessage();
    void updateProductSelection();
    void updateSugarLevel();
    // check interrupt T_idle

public:
    void handle();

};

#endif