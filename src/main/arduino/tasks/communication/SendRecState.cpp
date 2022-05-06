#include <ArduinoJson.h>
#include "../../utils/MsgService.h"
#include "SendRecState.h"

void SendRecState::handle() {
    StaticJsonDocument<100> doc;
    doc["status"] = getMachine()->getMachineState();
    MsgService.sendMsg(doc);
}