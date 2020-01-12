#include "storage_charge/storage.h"
#include "storage_charge/block/block_storage.h"
#include "storage_charge/file/file_storage.h"
#include "storage_charge/object/object_storage.h"

typedef double (*StorageCharge)(int capacity, int months);

static StorageCharge create_storage_charge(StorageType type)
{
    switch (type)
    {
    case ST_BLOCK_STORAGE:
        return block_storage_charge;
    case ST_FILE_STORAGE:
        return file_storage_charge;
    case ST_OBJECT_STORAGE:
        return object_storage_charge;
    default:
        return 0;
    }
}

double storage_charge(const Storage* storage, int months)
{
    StorageCharge charge = create_storage_charge(storage->type);
    return charge != 0 ? charge(storage->capacity, months) : 0;
}

typedef int (*StorageLevel)(int months);

static StorageLevel create_storage_level(StorageType type)
{
    return type == ST_OBJECT_STORAGE ? object_storage_level : 0;
}

int storage_level(const Storage* storage, int months)
{
    StorageLevel level = create_storage_level(storage->type);
    return level != 0 ? level(months) : 0;
}
