#include <ArduinoJson.h>
#include "../../utils/MsgService.h"
#include "SendRecState.h"

void SendRecState::handle() {
    MsgService.sendMsg(getMachine()->getInfos());
    if (MsgService.isMsgAvailable()) {
        Msg* msg = MsgService.receiveMsg();
        if (getMachine()->getMachineState() == ASSISTANCE && 
            (msg->getContent() == "RECOVER" || msg->getContent() == "REFILL")) {
            getMachine()->setMachineState(READY);
        }
    }
}