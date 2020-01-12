#include "storage_charge/core/lease.h"
#include "storage_charge/core/storage.h"

double lease_charge(const Lease *lease)
{
    return storage_charge(lease->storage, lease->months);
}

int lease_level(const Lease *lease)
{
    return storage_level(lease->storage, lease->months);
}
