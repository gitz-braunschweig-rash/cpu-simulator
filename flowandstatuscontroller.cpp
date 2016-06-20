#include "flowandstatuscontroller.h"

FlowAndStatusController::FlowAndStatusController(StorageUnit &_storageUnit) : storageUnit(_storageUnit)
{
}

void FlowAndStatusController::executeCommand(u_int16_t _command, u_int16_t _secondHalfOfFirstOcted, u_int16_t _completeSecondOcted)
{
    if(COMMAND_JUMP_STATIC == _command)
    {
        storageUnit.setProgrammCounter( (_secondHalfOfFirstOcted<<8) + _completeSecondOcted);
        qDebug("COMMAND_JUMP_STATIC %u", (_secondHalfOfFirstOcted<<8) + _completeSecondOcted);
    }
    else if(COMMAND_JUMP_REGISTER == _command)
    {
        const u_int16_t register_value = storageUnit.getRegisterValue(_secondHalfOfFirstOcted);
        storageUnit.setProgrammCounter(register_value);

        qDebug("COMMAND_JUMP_REGISTER r%u to %u", _secondHalfOfFirstOcted, register_value);
    }
    else if(COMMAND_BRANCH_ON_EQUAL == _command)
    {
        u_int16_t r1_address = _secondHalfOfFirstOcted;
        u_int16_t r2_address = Helper::getFirstHalfOfOcted(_completeSecondOcted);
        u_int16_t r3_address = Helper::getSecondHalfOfOcted(_completeSecondOcted);

        u_int16_t r1_value = storageUnit.getRegisterValue(r1_address);
        u_int16_t r2_value = storageUnit.getRegisterValue(r2_address);
        u_int16_t r3_value = storageUnit.getRegisterValue(r3_address);

        qDebug("COMMAND_BRANCH_ON_EQUAL %u (r%u) == %u (r%u) JUMP %u (r%u)", r1_value, r1_address, r2_value, r2_address, r3_value, r3_address);

        if(r1_value != r2_value)
        {
            storageUnit.setProgrammCounter(r3_value);
        }
    }
    else
    {
        qDebug() << "[WARNING][FlowAndStatusController] Unknown Command:" << _command << _secondHalfOfFirstOcted << _completeSecondOcted;
    }
}
