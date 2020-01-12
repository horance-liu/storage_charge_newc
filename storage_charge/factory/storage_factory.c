#include "storage_charge/factory/storage_factory.h"
#include "storage_charge/block/block_storage.h"
#include "storage_charge/file/file_storage.h"
#include "storage_charge/object/object_storage.h"

typedef struct StorageBase
{
    StorageCharge charge;
    StorageLevel level;
} StorageBase;

static double storage_charge_default(int capacity, int months)
{
    return 0;
}

static int storage_level_default(int months)
{
    return 0;
}

static StorageBase storages[MAX_STORAGE_TYPE] = {
    {block_storage_charge,  storage_level_default},
    {file_storage_charge,   storage_level_default},
    {object_storage_charge, object_storage_level},
};

StorageCharge create_storage_charge(StorageType type)
{
    return type < MAX_STORAGE_TYPE ?
           storages[type].charge :
           storage_charge_default;
}

StorageLevel create_storage_level(StorageType type)
{
    return type < MAX_STORAGE_TYPE ?
           storages[type].level :
           storage_level_default;
}
