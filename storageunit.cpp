#include "storageunit.h"

StorageUnit::StorageUnit(QVector<u_int16_t> &_component_ram, QVector<u_int16_t> &_component_register, u_int16_t &_status_register, u_int16_t &_programm_counter, u_int16_t &_stack_pointer)  : component_ram(_component_ram), component_register(_component_register), status_register(_status_register), programm_counter(_programm_counter), stack_pointer(_stack_pointer)
{

}

u_int16_t StorageUnit::getRamValue(u_int16_t _address)
{
    if(isValidRamAddress(_address))
    {
        return component_ram[_address>>1];
    }
    else
    {
        qDebug() << "getRamValue The address is not valid. Exit" << _address;
        exit(0);
    }
}

void StorageUnit::setRamValue(u_int16_t _value, u_int16_t _address)
{
    if(isValidRamAddress(_address))
    {
        component_ram[_address>>1] = _value;
    }
    else
    {
        qDebug() << "setRamValue The address is not valid. Exit" << _address;
        exit(0);
    }
}

bool StorageUnit::isValidRamAddress(u_int16_t _value)
{
    return (_value%2==0);
}

u_int16_t StorageUnit::getRegisterValue(u_int16_t _address)
{
    if(isValidRegisterAddress(_address))
    {
        return(component_register[_address]);
    }
    else
    {
        qDebug() << "getRegisterValue The address is not valid. Exit" << _address;
        exit(0);
    }
}

void StorageUnit::setRegisterValue(u_int16_t _value, u_int16_t _address)
{
    if(isValidRegisterAddress(_address))
    {
        component_register[_address] = _value;
    }
    else
    {
        qDebug() << "setRegisterValue The address is not valid. Exit" << _address;
        exit(0);
    }
}

bool StorageUnit::isValidRegisterAddress(u_int16_t _value)
{
    if(_value > component_register.size())
    {
        return false;
    }
    return true;
}

u_int16_t StorageUnit::getRamValueViaRegister(u_int16_t _register_address)
{
    return getRamValue(getRegisterValue(_register_address));
}

void StorageUnit::setRamValueViaRegister(u_int16_t _register_with_value, u_int16_t _register_with_address)
{
    u_int16_t value = getRegisterValue(_register_with_value);
    u_int16_t address = getRegisterValue(_register_with_address);
    setRamValue(value,address);
}

u_int16_t StorageUnit::getStatusRegister()
{
    return this->status_register;
}

void StorageUnit::setStatusRegister(u_int16_t _value)
{
    status_register = _value;
}

u_int16_t StorageUnit::getProgrammCounter()
{
    return this->programm_counter;
}

void StorageUnit::setProgrammCounter(u_int16_t _value)
{
    programm_counter = _value;
}

u_int16_t StorageUnit::getStackPointer()
{
    return this->stack_pointer;
}

void StorageUnit::setStackPointer(u_int16_t _value)
{
    stack_pointer = _value;
}

void StorageUnit::pop(u_int16_t _register)
{
    setStackPointer(getStackPointer()+2);
    setRegisterValue(getRamValue(getStackPointer()),_register);
}

void StorageUnit::push(u_int16_t _register)
{
    setRamValue(getRegisterValue(_register),getStackPointer());
    setStackPointer(getStackPointer()-2);
}

void StorageUnit::executeCommand(u_int16_t _command, u_int16_t _secondHalfOfFirstOcted, u_int16_t _completeSecondOcted)
{
    if(_command == COMMAND_LOAD)
    {
        qDebug() << "COMMAND_LOAD into Register Address" << _secondHalfOfFirstOcted << "from RAM Address " << _completeSecondOcted;
        setRegisterValue(getRamValue(_completeSecondOcted), _secondHalfOfFirstOcted);
    }

    else if(_command == COMMAND_STORE)
    {
        qDebug() << "COMMAND_STORE into RAM Address" << _completeSecondOcted << "from Register Address " << _secondHalfOfFirstOcted;
        setRamValue(getRegisterValue(_secondHalfOfFirstOcted), _completeSecondOcted);
    }

    else if(_command == COMMAND_LOAD_REGISTER)
    {
        qDebug() << "COMMAND_LOAD_REGISTER into Register Address" << Helper::getFirstHalfOfOcted(_completeSecondOcted) << "from Register " << _secondHalfOfFirstOcted;
        setRegisterValue(getRamValueViaRegister(_secondHalfOfFirstOcted), Helper::getFirstHalfOfOcted(_completeSecondOcted));
    }

    else if(_command == COMMAND_STORE_REGISTER)
    {
        qDebug() << "COMMAND_STORE_REGISTER Value from Register " << _secondHalfOfFirstOcted << "into Address from Register " << Helper::getFirstHalfOfOcted(_completeSecondOcted);
        setRamValueViaRegister(_secondHalfOfFirstOcted, Helper::getFirstHalfOfOcted(_completeSecondOcted));
    }

    else if(_command == COMMAND_PUSH)
    {
        qDebug() << "COMMAND_PUSH Register " << _secondHalfOfFirstOcted << " to " << QString::number(getStackPointer(),16);
        push(_secondHalfOfFirstOcted);
    }

    else if(_command == COMMAND_POP)
    {
        qDebug() << "COMMAND_POP Register " << _secondHalfOfFirstOcted << " from " << QString::number(getStackPointer(),16);
        pop(_secondHalfOfFirstOcted);
    }

    else
    {
        qDebug() << "[ERROR][STORAGE UNIT][executeCommand] received " << QString::number(_command,16) << QString::number(_secondHalfOfFirstOcted,16) << QString::number(_completeSecondOcted,16);
    }
}
