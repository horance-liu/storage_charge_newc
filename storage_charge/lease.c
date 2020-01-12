#include "storage_charge/lease.h"
#include "storage_charge/storage.h"

double lease_charge(const Lease *lease)
{
    return storage_charge(lease->storage, lease->months);
}

static int level_for_storage(const Storage* storage, int months)
{
    return storage_level(storage, months);
}

int lease_level(const Lease *lease)
{
    return level_for_storage(lease->storage, lease->months);
}
