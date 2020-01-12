#include "storage_charge/storage.h"
#include "storage_charge/lease.h"

void charge(const Tenant* tenant, double* total, int* levels)
{
    for (int i = 0; i < tenant->numOfLeases && i < MAX_NUM_LEASE; i++)
    {
        const Lease* lease = tenant->leases[i];
        *levels += lease_level(lease);
        *total += lease_charge(lease);
    }
}
