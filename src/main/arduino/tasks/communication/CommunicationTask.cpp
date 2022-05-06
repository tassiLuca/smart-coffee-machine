#include "CommunicationTask.h"
#include "SendRecState.h"

CommunicationTask::CommunicationTask(const int period, Machine* machine) 
    : BaseTask(period, machine)
{
    this->init(new SendRecState());
}