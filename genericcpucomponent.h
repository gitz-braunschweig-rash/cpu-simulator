#ifndef GENERICCPUCOMPONENT_H
#define GENERICCPUCOMPONENT_H

#include <QVector>

class GenericCpuComponent
{
public:
    GenericCpuComponent();

    virtual void executeCommand(u_int16_t _command, u_int16_t _secondHalfOfFirstOcted, u_int16_t _completeSecondOcted) = 0;
};

#endif // GENERICCPUCOMPONENT_H
