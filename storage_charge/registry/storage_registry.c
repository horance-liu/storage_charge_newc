#include "storage_charge/registry/storage_registry.h"

static inline double storage_charge_default(int capacity, int months)
{
    return 0;
}

static inline int storage_level_default(int months)
{
    return 0;
}

static StorageBase storages[MAX_STORAGE_TYPE] = {};

void storage_registry_init()
{
    for (int i = 0; i < MAX_STORAGE_TYPE; i++)
    {
        storages[i].charge = storage_charge_default;
        storages[i].level = storage_level_default;
    }
}

void storage_registry_register(StorageType type, StorageInstall install)
{
    if (type < MAX_STORAGE_TYPE)
    {
        install(&storages[type]);
    }
}

static StorageBase storage_default = {
    storage_charge_default, storage_level_default
};

StorageBase* storage_registry_find(StorageType type)
{
    return type < MAX_STORAGE_TYPE ? &storages[type] : &storage_default;
}
