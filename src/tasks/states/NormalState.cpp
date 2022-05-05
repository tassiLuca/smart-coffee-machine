#include "NormalState.h"
#include "SelfTestState.h"

#define CHECK_TIME 20000

NormalState::NormalState() {
    enteredTime = millis();
}

void NormalState::handle() {
    if (millis() - enteredTime > CHECK_TIME && getMachine()->getMachineState() == READY) {
        getMachine()->setMachineState(TESTING);
        getTask()->stateTransition(new SelfTestState());
    }
}
