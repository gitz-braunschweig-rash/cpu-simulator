#include "hardware_instruction_decoder.h"

HardwareInstructionDecoder::HardwareInstructionDecoder(StorageUnit &_storageUnit) : storageUnit(_storageUnit), alu(_storageUnit), flowcontroller(_storageUnit)
{
}

void HardwareInstructionDecoder::decode(u_int16_t _opcode)
{
    opcodeFirstHalf = _opcode;
    opcodeSecondHalf = _opcode;
    secondOcted = _opcode;

    opcodeFirstHalf = opcodeFirstHalf>> 12;

    opcodeSecondHalf  = opcodeSecondHalf << 4;
    opcodeSecondHalf = opcodeSecondHalf >> 12;

    secondOcted = secondOcted<<8;
    secondOcted = secondOcted>>8;

    delegateCommand(opcodeFirstHalf,opcodeSecondHalf,secondOcted);
}

void HardwareInstructionDecoder::delegateCommand(u_int16_t _command, u_int16_t _secondHalfOfFirstOcted, u_int16_t _completeSecondOcted)
{
    if(COMMAND_ADD == _command)
    {
        alu.executeCommand(_command,_secondHalfOfFirstOcted,_completeSecondOcted);
    }

    else if(COMMAND_SUBTRACT == _command)
    {
        alu.executeCommand(_command,_secondHalfOfFirstOcted,_completeSecondOcted);
    }

    else if(COMMAND_DIVISION == _command)
    {
        alu.executeCommand(_command,_secondHalfOfFirstOcted,_completeSecondOcted);
    }

    else if(COMMAND_MULTIPLY == _command)
    {
        alu.executeCommand(_command,_secondHalfOfFirstOcted,_completeSecondOcted);
    }
    else if(COMMAND_ADD_VALUE_TO_REGISTER_SECOND_OCTED == _command)
    {
        alu.executeCommand(_command,_secondHalfOfFirstOcted,_completeSecondOcted);
    }
    else if(COMMAND_ADD_VALUE_TO_REGISTER_FIRST_OCTED == _command)
    {
        alu.executeCommand(_command,_secondHalfOfFirstOcted,_completeSecondOcted);
    }
    else if(COMMAND_STORE == _command)
    {
        storageUnit.executeCommand(_command,_secondHalfOfFirstOcted,_completeSecondOcted);
    }
    else if(COMMAND_LOAD == _command)
    {
        storageUnit.executeCommand(_command,_secondHalfOfFirstOcted,_completeSecondOcted);
    }
    else if(COMMAND_JUMP_STATIC == _command)
    {
        flowcontroller.executeCommand(_command,_secondHalfOfFirstOcted,_completeSecondOcted);
    }
    else if(COMMAND_JUMP_REGISTER == _command)
    {
        flowcontroller.executeCommand(_command,_secondHalfOfFirstOcted,_completeSecondOcted);
    }
    else if(COMMAND_BRANCH_ON_EQUAL == _command)
    {
        flowcontroller.executeCommand(_command,_secondHalfOfFirstOcted,_completeSecondOcted);
    }
    else if(COMMAND_STORE_REGISTER == _command)
    {
        storageUnit.executeCommand(_command,_secondHalfOfFirstOcted,_completeSecondOcted);
    }
    else if(COMMAND_LOAD_REGISTER == _command)
    {
        storageUnit.executeCommand(_command,_secondHalfOfFirstOcted,_completeSecondOcted);
    }
    else if(COMMAND_POP == _command)
    {
        storageUnit.executeCommand(_command,_secondHalfOfFirstOcted,_completeSecondOcted);
    }
    else if(COMMAND_PUSH == _command)
    {
        storageUnit.executeCommand(_command,_secondHalfOfFirstOcted,_completeSecondOcted);
    }
    else if(COMMAND_SET_STACK_POINTER == _command)
    {
        storageUnit.executeCommand(_command,_secondHalfOfFirstOcted,_completeSecondOcted);
    }
}
