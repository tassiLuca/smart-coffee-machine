#include "CompletedState.h"
#include "IdleState.h"

#define TIMEOUT_COMPLETED 10000

/**
 * @todo reset posizione servo 
 */

CompletedState::CompletedState() {
    enteredTime = millis();
}

void CompletedState::handle() {
    if (checkTransition()) {
        if (getMachine()->productsAvailable()) {
            getMachine()->setMachineState(READY);
            getMachine()->resetMotorPosition();
        } else {
            getMachine()->setMachineState(ASSISTANCE);
        }
        getTask()->stateTransition(new IdleState());
    }
}

bool CompletedState::checkTransition() {
    return (millis() - enteredTime > TIMEOUT_COMPLETED) || getMachine()->getDistance() > 40;
}
