#include "storage_charge/storage.h"
#include "storage_charge/lease.h"

static int level_for_lease(const Lease* lease)
{
    return lease_level(lease);
}

void charge(const Tenant* tenant, double* total, int* levels)
{
    for (int i = 0; i < tenant->numOfLeases && i < MAX_NUM_LEASE; i++)
    {
        const Lease* lease = tenant->leases[i];
        *levels += level_for_lease(lease);
        *total += lease_charge(lease);
    }
}
