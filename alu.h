#ifndef ALU_H
#define ALU_H

#include "genericcpucomponent.h"
#include "storageunit.h"
#include "helper.h"
#include "command_constants.h"

class Alu : GenericCpuComponent
{
public:
    Alu(StorageUnit& _storageUnit);

    StorageUnit& storageUnit;

    virtual void executeCommand(u_int16_t _command, u_int16_t _secondHalfOfFirstOcted, u_int16_t _completeSecondOcted);


};

#endif // ALU_H
