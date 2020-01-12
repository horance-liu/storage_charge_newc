#include "storage_charge/storage.h"

#define BASIC_FILE_STORAGE_MONTHS 2
#define BASIC_OBJECT_STORAG_MONTHS 3
#define MONTHS_OF_YEAR 12

static double charge_for_lease(const Lease *lease)
{
    double price = 0;
    switch (lease->storage->type)
    {
    case ST_BLOCK_STORAGE:
        price += 40;
        if (lease->storage->capacity > BASIC_BLOCK_SIZE)
        {
            double exceed = lease->storage->capacity - BASIC_BLOCK_SIZE;
            price += lease->months * exceed * 3;
        }
        break;
    case ST_FILE_STORAGE:
        price += 20;
        if (lease->months > BASIC_FILE_STORAGE_MONTHS)
        {
            double exceed = lease->months - BASIC_FILE_STORAGE_MONTHS;
            price += exceed * 1.5;
        }
        break;
    case ST_OBJECT_STORAGE:
        price += 10;
        if (lease->months > BASIC_OBJECT_STORAG_MONTHS)
        {
            double exceed = lease->months - BASIC_OBJECT_STORAG_MONTHS;
            price += exceed * lease->storage->capacity * 1.5;
        }
        break;
    default:
        break;
    }
    return price;
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
