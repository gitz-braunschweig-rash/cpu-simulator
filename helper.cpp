#include "helper.h"

Helper::Helper(QVector<u_int16_t> &_ram, QVector<u_int16_t> &_registers) : ram(_ram), registers(_registers)
{

}

bool Helper::readRamFile(const QString &_file)
{
    QFile file(_file);

    if(!file.open(QIODevice::ReadOnly))
    {
        qDebug() << "[ERROR] Helper::readRamFile could not open " << _file;
        return false;
    }

    char buffer[1024];


    size_t counter = 0;
    while (file.readLine(buffer,1023)) //zero byte needs on byte, so 1024-1=1023 read
    {
        if(counter >= ram.size())
        {
            qDebug() << "[WARNING] counter >= ram.size()" << counter << ">=" << ram.size();
            break;
        }

        QString line(buffer);
        if(line.contains("#"))
        {
            QStringList temp = line.split("#");
            line = temp.first();
        }

        bool ok;
        u_int16_t value = line.toUShort(&ok,16);
        ram[counter] = value;
        counter++;
    }

    return true;
}

bool Helper::readRegisterFile(const QString &_file)
{
    QFile file(_file);

    if(!file.open(QIODevice::ReadOnly))
    {
        qDebug() << "[ERROR] Helper::readRegisterFile could not open " << _file;
        return false;
    }

    char buffer[1024];


    size_t counter = 0;
    while (file.readLine(buffer,1023)) //zero byte needs on byte, so 1024-1=1023 read
    {
        if(counter >= registers.size())
        {
            qDebug() << "[WARNING] counter >= registers.size()" << counter << ">=" << registers.size();
            break;
        }

        QString line(buffer);
        if(line.contains("#"))
        {
            QStringList temp = line.split("#");
            line = temp.first();
        }

        bool ok;
        u_int16_t value = line.toUShort(&ok,16);
        registers[counter] = value;
        counter++;
    }

    return true;
}

u_int16_t Helper::getFirstHalfOfOcted(u_int16_t _value)
{
    _value = _value << 8;
    _value = _value >> 8;
    _value = _value >> 4;
    return _value;
}

u_int16_t Helper::getSecondHalfOfOcted(u_int16_t _value)
{
    _value = _value << 12;
    _value = _value >> 12;
    return _value;

}
