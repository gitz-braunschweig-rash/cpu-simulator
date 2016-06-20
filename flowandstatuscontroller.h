#ifndef FLOWANDSTATUSCONTROLLER_H
#define FLOWANDSTATUSCONTROLLER_H

#include "genericcpucomponent.h"
#include "storageunit.h"

class FlowAndStatusController : GenericCpuComponent
{
public:
    FlowAndStatusController(StorageUnit& _storageUnit);

    virtual void executeCommand(u_int16_t _command, u_int16_t _secondHalfOfFirstOcted, u_int16_t _completeSecondOcted);
    StorageUnit& storageUnit;

};

#endif // FLOWANDSTATUSCONTROLLER_H
