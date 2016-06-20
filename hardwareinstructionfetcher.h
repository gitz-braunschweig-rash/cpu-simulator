#ifndef HARDWAREINSTRUCTIONFETCHER_H
#define HARDWAREINSTRUCTIONFETCHER_H

#include "storageunit.h"

class HardwareInstructionFetcher
{
public:
    HardwareInstructionFetcher(StorageUnit& _storageUnit);
    StorageUnit& storageUnit;

    u_int16_t getInstruction(u_int16_t _programmCounter);
    u_int16_t fetchInstruction(u_int16_t _programmCounter);
};

#endif // HARDWAREINSTRUCTIONFETCHER_H
