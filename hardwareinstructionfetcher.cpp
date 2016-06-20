#include "hardwareinstructionfetcher.h"

HardwareInstructionFetcher::HardwareInstructionFetcher(StorageUnit& _storageUnit) : storageUnit(_storageUnit)
{
}

u_int16_t HardwareInstructionFetcher::getInstruction(u_int16_t _programmCounter)
{
    return storageUnit.getRamValue(_programmCounter);
}

u_int16_t HardwareInstructionFetcher::fetchInstruction(u_int16_t _programmCounter)
{
    return getInstruction(_programmCounter);
}
