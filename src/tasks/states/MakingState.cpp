#include "MakingState.h"
#include "ReadyState.h"

void MakingState::handle() {
    Serial.println("MAKING-STATE");
    if (!this->getTask()->getMachine()->isMaking() && 
        this->getTask()->getMachine()->getTotalAmountOfProducts() > 0) {
            this->getTask()->stateTransition(new ReadyState());
    }
}