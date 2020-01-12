#include "storage_charge/storage_factory.h"
#include "storage_charge/block/block_storage.h"
#include "storage_charge/file/file_storage.h"
#include "storage_charge/object/object_storage.h"

static double storage_charge_default(int capacity, int months)
{
    return 0;
}

StorageCharge create_storage_charge(StorageType type)
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
        return storage_charge_default;
    }
}

static int storage_level_default(int months)
{
    return 0;
}

StorageLevel create_storage_level(StorageType type)
{
    return type == ST_OBJECT_STORAGE ? object_storage_level : storage_level_default;
}
