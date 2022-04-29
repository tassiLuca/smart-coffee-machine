#include "AssistanceState.h"
#include "ReadyState.h"

void AssistanceState::handle() {
    getMachine()->setMachineState(ASSISTANCE);
    getMachine()->displayMessage("ASSISTANCE REQUIRED");
    if (getMachine()->getMachineState() == READY) {
        getTask()->stateTransition(new ReadyState());
    }
 }