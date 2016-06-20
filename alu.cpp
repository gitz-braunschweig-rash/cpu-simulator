#include "alu.h"

Alu::Alu(StorageUnit &_storageUnit) : storageUnit(_storageUnit)
{

}

void Alu::executeCommand(u_int16_t _command, u_int16_t _secondHalfOfFirstOcted, u_int16_t _completeSecondOcted)
{
    if(_command == COMMAND_ADD)
    {
        u_int16_t r1_address = _secondHalfOfFirstOcted;
        u_int16_t r2_address = Helper::getFirstHalfOfOcted(_completeSecondOcted);
        u_int16_t r3_address = Helper::getSecondHalfOfOcted(_completeSecondOcted);

        qDebug("COMMAND_ADD r%u, r%u into r%u", r1_address ,r2_address ,r3_address);

        u_int16_t r1_value = storageUnit.getRegisterValue(r1_address);
        u_int16_t r2_value = storageUnit.getRegisterValue(r2_address);
        u_int16_t r3_value = storageUnit.getRegisterValue(r3_address);

        r3_value = r1_value + r2_value;

        u_int32_t overrun_test = r1_value + r2_value;

        storageUnit.setRegisterValue(r3_value, r3_address);

        storageUnit.setStatusRegister( overrun_test > r3_value ? storageUnit.getStatusRegister() | 0x0002 : storageUnit.getStatusRegister()  );

    }

    else if(_command == COMMAND_SUBTRACT)
    {
        u_int16_t r1_address = _secondHalfOfFirstOcted;
        u_int16_t r2_address = Helper::getFirstHalfOfOcted(_completeSecondOcted);
        u_int16_t r3_address = Helper::getSecondHalfOfOcted(_completeSecondOcted);

        qDebug("COMMAND_SUBTRACT r%u - r%u into r%u", r1_address ,r2_address ,r3_address);

        u_int16_t r1_value = storageUnit.getRegisterValue(r1_address);
        u_int16_t r2_value = storageUnit.getRegisterValue(r2_address);
        u_int16_t r3_value = storageUnit.getRegisterValue(r3_address);

        r3_value = r1_value - r2_value;

        storageUnit.setRegisterValue(r3_value, r3_address);

        storageUnit.setStatusRegister( r2_value > r1_value ? storageUnit.getStatusRegister() | 0x0001 : storageUnit.getStatusRegister()  );
    }

    else if(_command == COMMAND_MULTIPLY)
    {
        u_int16_t r1_address = _secondHalfOfFirstOcted;
        u_int16_t r2_address = Helper::getFirstHalfOfOcted(_completeSecondOcted);
        u_int16_t r3_address = Helper::getSecondHalfOfOcted(_completeSecondOcted);

        qDebug("COMMAND_MULTIPLY r%u * r%u into r%u", r1_address ,r2_address ,r3_address);


        u_int16_t r1_value = storageUnit.getRegisterValue(r1_address);
        u_int16_t r2_value = storageUnit.getRegisterValue(r2_address);
        u_int16_t r3_value = storageUnit.getRegisterValue(r3_address);

        r3_value = r1_value * r2_value;

        storageUnit.setRegisterValue(r3_value, r3_address);
    }

    else if(_command == COMMAND_DIVISION)
    {
        u_int16_t r1_address = _secondHalfOfFirstOcted;
        u_int16_t r2_address = Helper::getFirstHalfOfOcted(_completeSecondOcted);
        u_int16_t r3_address = Helper::getSecondHalfOfOcted(_completeSecondOcted);

        qDebug("COMMAND_DIVISION r%u / r%u into r%u", r1_address ,r2_address ,r3_address);

        u_int16_t r1_value = storageUnit.getRegisterValue(r1_address);
        u_int16_t r2_value = storageUnit.getRegisterValue(r2_address);
        u_int16_t r3_value = storageUnit.getRegisterValue(r3_address);

        r3_value = (u_int16_t) (r1_value / r2_value);

        storageUnit.setRegisterValue(r3_value, r3_address);
    }

    else if(_command == COMMAND_ADD_VALUE_TO_REGISTER_SECOND_OCTED)
    {
        u_int16_t r1_address = _secondHalfOfFirstOcted;
        u_int16_t value = _completeSecondOcted;

        qDebug("COMMAND_ADD_VALUE_TO_REGISTER_SECOND_OCTED r%u %u", r1_address ,value);

        u_int16_t r1_value = storageUnit.getRegisterValue(r1_address);
        u_int32_t overrun_test = r1_value + value;
        r1_value = r1_value + value;
        storageUnit.setRegisterValue(r1_value, r1_address);
        storageUnit.setStatusRegister( overrun_test > r1_value ? storageUnit.getStatusRegister() | 0x0002 : storageUnit.getStatusRegister()  );



    }

    else if(_command == COMMAND_ADD_VALUE_TO_REGISTER_FIRST_OCTED)
    {
        u_int16_t r1_address = _secondHalfOfFirstOcted;
        u_int16_t value = _completeSecondOcted << 8; //add the value to the first 8 bits. done via shift.

        u_int16_t r1_value = storageUnit.getRegisterValue(r1_address);
        r1_value = r1_value + value;

        u_int32_t overrun_test = r1_value + value;
        storageUnit.setRegisterValue(r1_value, r1_address);
        storageUnit.setStatusRegister( overrun_test > r1_value ? storageUnit.getStatusRegister() | 0x0002 : storageUnit.getStatusRegister()  );


        qDebug("COMMAND_ADD_VALUE_TO_REGISTER_FIRST_OCTED r%u %u", r1_address ,(value>>8));

    }

    else
    {
        qDebug() << "[ERROR][ALU][executeCommand] received " << QString::number(_command,16) << QString::number(_secondHalfOfFirstOcted,16) << QString::number(_completeSecondOcted,16);
    }
}

