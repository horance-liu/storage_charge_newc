#include "storage_charge/storage.h"
#include "storage_charge/block/block_storage.h"
#include "storage_charge/file/file_storage.h"
#include "storage_charge/object/object_storage.h"

double storage_charge(const Storage* storage, int months)
{
    switch (storage->type)
    {
    case ST_BLOCK_STORAGE:
        return block_storage_charge(storage->capacity, months);
    case ST_FILE_STORAGE:
        return file_storage_charge(months);
    case ST_OBJECT_STORAGE:
        return object_storage_charge(storage->capacity, months);
    default:
        return 0;
    }
}

static int level_for_object_storage(int months)
{
    return object_storage_level(months);
}

int storage_level(const Storage* storage, int months)
{
    if (storage->type == ST_OBJECT_STORAGE)
    {
        return level_for_object_storage(months);
    }
    return 0;
}
