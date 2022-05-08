#include <ArduinoJson.h>
#include "../../utils/MsgService.h"
#include "SendRecState.h"

void SendRecState::handle() {
    MsgService.sendMsg(getMachine()->getInfos());
    if (MsgService.isMsgAvailable()) {
        Msg* msg = MsgService.receiveMsg();
        if (getMachine()->getMachineState() == ASSISTANCE) {
            if (msg->getContent() == "RECOVER") {
                getMachine()->setMachineState(READY);
            } else if (msg->getContent() == "REFILL") {
                getMachine()->refill();
                getMachine()->setMachineState(READY);
            }
        } 
        delete msg;
    }
}