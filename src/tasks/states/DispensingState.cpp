#include "DispensingState.h"
#include "IdleState.h"

void DispensingState::handle() {
    getMachine()->make();
    if (!getMachine()->isMaking()) {
        getMachine()->setMachineState(READY);
        getTask()->stateTransition(new IdleState());
    }
}