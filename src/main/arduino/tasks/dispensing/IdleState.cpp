#include "IdleState.h"
#include "DispensingState.h"

void IdleState::handle() {
    if (getMachine()->getMachineState() == DISPENSING) {
        getTask()->stateTransition(new DispensingState());
    }
}