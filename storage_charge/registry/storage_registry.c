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

static StorageCharge safe_storage_charge(StorageCharge charge)
{
    return charge != 0 ? charge : storage_charge_default;
}

static StorageLevel safe_storage_level(StorageLevel level)
{
    return level != 0 ? level : storage_level_default;
}

void storage_registry_register(StorageType type, StorageCharge charge, StorageLevel level)
{
    if (type < MAX_STORAGE_TYPE)
    {
        storages[type].charge = safe_storage_charge(charge);
        storages[type].level  = safe_storage_level(level);
    }
}

static StorageBase storage_default= {
    storage_charge_default, storage_level_default
};

StorageBase* storage_find(StorageType type)
{
    return type < MAX_STORAGE_TYPE ? &storages[type] : &storage_default;
}
