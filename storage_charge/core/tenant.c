#include "storage_charge/core/tenant.h"
#include "storage_charge/core/lease.h"

void tenant_init(Tenant* tenant)
{
    tenant->numOfLeases = 0;
}

void tenant_add(Tenant* tenant, Lease* lease)
{
    if (tenant->numOfLeases < MAX_NUM_LEASE)
    {
        tenant->leases[tenant->numOfLeases++] = lease;
    }
}

void tenant_charge(const Tenant* tenant, double* total, int* levels)
{
    for (int i = 0; i < tenant->numOfLeases && i < MAX_NUM_LEASE; i++)
    {
        const Lease* lease = tenant->leases[i];
        *levels += lease_level(lease);
        *total += lease_charge(lease);
    }
}
