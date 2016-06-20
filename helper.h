#ifndef HELPER_H
#define HELPER_H

#include <QVector>
#include <QFile>
#include <QString>
#include <QStringList>
#include <QDebug>

class Helper
{
public:
    Helper(    QVector<u_int16_t>& _ram, QVector<u_int16_t>& _registers);
    bool readRamFile(const QString& _file);
    bool readRegisterFile(const QString& _file);
    QVector<u_int16_t>& ram;
    QVector<u_int16_t>& registers;

    static u_int16_t getFirstHalfOfOcted(u_int16_t _value);
    static u_int16_t getSecondHalfOfOcted(u_int16_t _value);
};

#endif // HELPER_H
