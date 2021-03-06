#include "MakingState.h"
#include "AssistanceState.h"
#include "ReadyState.h"

void MakingState::handle() {
    if (getMachine()->getMachineState() == ASSISTANCE) {
        getTask()->stateTransition(new AssistanceState());
    } else if (getMachine()->getMachineState() == READY) {
        getTask()->stateTransition(new ReadyState());
    }
}