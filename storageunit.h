#ifndef STORAGEUNIT_H
#define STORAGEUNIT_H

#include <QVector>
#include <QDebug>
#include "helper.h"
#include "genericcpucomponent.h"
#include "command_constants.h"

class StorageUnit : GenericCpuComponent
{
public:
    StorageUnit(QVector<u_int16_t> &_component_ram, QVector<u_int16_t> &_component_register, u_int16_t& _status_register, u_int16_t& _programm_counter, u_int16_t& _stack_pointer);
    QVector<u_int16_t>& component_ram;
    QVector<u_int16_t>& component_register;
    u_int16_t& status_register;
    u_int16_t& programm_counter;
    u_int16_t& stack_pointer;

    u_int16_t getRamValue(u_int16_t _address);
    void setRamValue(u_int16_t _value, u_int16_t _address);
    bool isValidRamAddress(u_int16_t _value);

    u_int16_t getRegisterValue(u_int16_t _address);
    void setRegisterValue(u_int16_t _value, u_int16_t _address);
    bool isValidRegisterAddress(u_int16_t _value);

    u_int16_t getRamValueViaRegister(u_int16_t _register_address);
    void setRamValueViaRegister(u_int16_t _register_with_value, u_int16_t _register_with_address);

    u_int16_t getStatusRegister();
    void setStatusRegister(u_int16_t _value);

    u_int16_t getProgrammCounter();
    void setProgrammCounter(u_int16_t _value);

    u_int16_t getStackPointer();
    void setStackPointer(u_int16_t _value);

    void pop(u_int16_t _register);
    void push(u_int16_t _register);

    //opcodes
    virtual void executeCommand(u_int16_t _command, u_int16_t _secondHalfOfFirstOcted, u_int16_t _completeSecondOcted);


};

#endif // STORAGEUNIT_H
