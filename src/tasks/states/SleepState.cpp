#include <avr/sleep.h>
#include "SleepState.h"
#include "ReadyState.h"

void SleepState::handle() {
    getMachine()->displayMessage("SLEEP MODE");
    set_sleep_mode(SLEEP_MODE_PWR_DOWN);
    sleep_enable();
    sleep_mode();
    /** The program will continue from here when
     *  an interrupt from the pir sensor occours. */
    getTask()->stateTransition(new ReadyState());
}