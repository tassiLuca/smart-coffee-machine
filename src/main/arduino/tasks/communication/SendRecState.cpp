#include <ArduinoJson.h>
#include "../../utils/MsgService.h"
#include "SendRecState.h"

void SendRecState::handle() {
    MsgService.sendMsg(getMachine()->getInfos());
}