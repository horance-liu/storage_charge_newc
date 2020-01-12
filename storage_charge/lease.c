#include "storage_charge/lease.h"
#include "storage_charge/storage.h"

static double charge_for_storage(const Storage* storage, int months)
{
    return storage_charge(storage, months);
}

double lease_charge(const Lease *lease)
{
    return charge_for_storage(lease->storage, lease->months);
}

#define MONTHS_OF_YEAR 12

static int level_for_storage(const Storage* storage, int months)
{
    if ((storage->type == ST_OBJECT_STORAGE) && (months > MONTHS_OF_YEAR))
    {
        return 1;
    }
    return 0;
}

int lease_level(const Lease *lease)
{
    return level_for_storage(lease->storage, lease->months);
}
