#include "storage_charge/core/storage.h"
#include "storage_charge/registry/storage_registry.h"

double storage_charge(const Storage* storage, int months)
{
    StorageBase* base = storage_registry_find(storage->type);
    return base->charge(storage->capacity, months);
}

int storage_level(const Storage* storage, int months)
{
    StorageBase* base = storage_registry_find(storage->type);
    return base->level(months);
}
