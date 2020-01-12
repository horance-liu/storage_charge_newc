#include "storage_charge/storage.h"
#include "storage_charge/block/block_storage.h"
#include "storage_charge/file/file_storage.h"
#include "storage_charge/object/object_storage.h"

static double charge_for_object_storage(int capacity, int months)
{
    return object_storage_charge(capacity, months);
}

double storage_charge(const Storage* storage, int months)
{
    switch (storage->type)
    {
    case ST_BLOCK_STORAGE:
        return block_storage_charge(storage->capacity, months);
    case ST_FILE_STORAGE:
        return file_storage_charge(months);
    case ST_OBJECT_STORAGE:
        return charge_for_object_storage(storage->capacity, months);
    default:
        return 0;
    }
}

#define MONTHS_OF_YEAR 12

static int level_for_object_storage(int months)
{
    return months > MONTHS_OF_YEAR ? 1 : 0;
}

int storage_level(const Storage* storage, int months)
{
    if (storage->type == ST_OBJECT_STORAGE)
    {
        return level_for_object_storage(months);
    }
    return 0;
}
