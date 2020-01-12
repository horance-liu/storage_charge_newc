#include "storage_charge/storage.h"
#include "storage_charge/storage_factory.h"

double storage_charge(const Storage* storage, int months)
{
    StorageCharge charge = create_storage_charge(storage->type);
    return charge(storage->capacity, months);
}

static StorageLevel create_storage_level(StorageType type)
{
    return create_storage_level_with_type(type);
}

int storage_level(const Storage* storage, int months)
{
    StorageLevel level = create_storage_level(storage->type);
    return level(months);
}
