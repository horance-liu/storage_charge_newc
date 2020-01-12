#include "storage_charge/storage.h"
#include "storage_charge/storage_factory.h"
#include "storage_charge/object/object_storage.h"

double storage_charge(const Storage* storage, int months)
{
    StorageCharge charge = create_storage_charge(storage->type);
    return charge(storage->capacity, months);
}

typedef int (*StorageLevel)(int months);

static int storage_level_default(int months)
{
    return 0;
}

static StorageLevel create_storage_level(StorageType type)
{
    return type == ST_OBJECT_STORAGE ? object_storage_level : storage_level_default;
}

int storage_level(const Storage* storage, int months)
{
    StorageLevel level = create_storage_level(storage->type);
    return level(months);
}
