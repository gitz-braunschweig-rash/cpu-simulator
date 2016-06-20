#ifndef HARDWARE_INSTRUCTION_DECODER_H
#define HARDWARE_INSTRUCTION_DECODER_H

#include "genericcpucomponent.h"
#include "storageunit.h"
#include "alu.h"
#include "command_constants.h"
#include "flowandstatuscontroller.h"

class HardwareInstructionDecoder
{
public:
    HardwareInstructionDecoder(StorageUnit& _storageUnit);
    StorageUnit& storageUnit;
    void decode(u_int16_t _opcode);
    void delegateCommand(u_int16_t _command, u_int16_t _secondHalfOfFirstOcted, u_int16_t _completeSecondOcted);

    u_int16_t opcodeFirstHalf;
    u_int16_t opcodeSecondHalf;
    u_int16_t secondOcted;

    Alu alu;
    FlowAndStatusController flowcontroller;

};

#endif // HARDWARE_INSTRUCTION_DECODER_H
