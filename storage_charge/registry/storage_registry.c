#include "storage_charge/registry/storage_registry.h"
#include <stdlib.h>

static inline double storage_charge_default(int capacity, int months)
{
    return 0;
}

static inline int storage_level_default(int months)
{
    return 0;
}

static StorageBase storage_default = {
    storage_charge_default, storage_level_default
};

static StorageBase* storages = 0;
static StorageType storage_size = 0;

static void storage_registroy_do_init(StorageType size)
{
    storage_size = size;
    for (int i = 0; i < storage_size; i++)
    {
        storages[i] = storage_default;
    }
}

void storage_registry_init(StorageType size)
{
    storages = (StorageBase*)malloc(sizeof(StorageBase) * size);
    if (storages != 0) {
        storage_registroy_do_init(size);
    }
}

void storage_registry_destroy()
{
    if (storages != 0) {
        free(storages);
    }
    storage_size = 0;
}

void storage_registry_register(StorageType type, StorageInstall install)
{
    if (type < storage_size)
    {
        install(&storages[type]);
    }
}

StorageBase* storage_registry_find(StorageType type)
{
    return type < storage_size ? &storages[type] : &storage_default;
}
