#include "DispensingState.h"
#include "CompletedState.h"

void DispensingState::handle() {
    getMachine()->make();
    if (!getMachine()->isMaking()) {
        getTask()->stateTransition(new CompletedState());
    }
}
