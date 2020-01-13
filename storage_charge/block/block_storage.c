#include "storage_charge/block/block_storage.h"
#include "storage_charge/core/storage_type.h"
#include "storage_charge/registry/storage_registry.h"

#define BASIC_BLOCK_SIZE 1024 /* 块存储的最大值 */

static double block_storage_charge(int capacity, int months)
{
    double price = 40;
    if (capacity > BASIC_BLOCK_SIZE)
    {
        double exceed = capacity - BASIC_BLOCK_SIZE;
        price += months * exceed * 3;
    }
    return price;
}

static void block_storage_install(StorageBase* storage)
{
    storage->charge = block_storage_charge;
}

void block_storage_register_with_type(StorageType type)
{
    storage_registry_register(type, block_storage_install);
}
