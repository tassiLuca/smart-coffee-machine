#include "SelfTestState.h"
#include "NormalState.h"

#define MIN_TEMP 17.0
#define MAX_TEMP 25.0

void SelfTestState::handle() {
    getMachine()->test();
    if (!getMachine()->isTesting()) {
        if (getMachine()->getTemperature() > MIN_TEMP && getMachine()->getTemperature() < MAX_TEMP) {
            getMachine()->setMachineState(READY);
        } else {
            getMachine()->setMachineState(ASSISTANCE);
        }
        getTask()->stateTransition(new NormalState());
    }
}