#include "storage_charge/core/storage.h"
#include "storage_charge/factory/storage_factory.h"

double storage_charge(const Storage* storage, int months)
{
    StorageCharge charge = create_storage_charge(storage->type);
    return charge(storage->capacity, months);
}

int storage_level(const Storage* storage, int months)
{
    StorageLevel level = create_storage_level(storage->type);
    return level(months);
}