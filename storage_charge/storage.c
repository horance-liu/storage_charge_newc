#include "storage_charge/storage.h"
#include "storage_charge/lease.h"

#define MONTHS_OF_YEAR 12

static double charge_for_lease(const Lease *lease)
{
    return lease_charge(lease);
}

static int level_for_lease(const Lease* lease)
{
    if ((lease->storage->type == ST_OBJECT_STORAGE)
            && (lease->months > MONTHS_OF_YEAR))
    {
        return 1;
    }
    return 0;
}

void charge(const Tenant* tenant, double* total, int* levels)
{
    for (int i = 0; i < tenant->numOfLeases && i < MAX_NUM_LEASE; i++)
    {
        const Lease* lease = tenant->leases[i];
        *levels += level_for_lease(lease);
        *total += charge_for_lease(lease);
    }
}
