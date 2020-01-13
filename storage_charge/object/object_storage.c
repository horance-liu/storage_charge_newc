#include "storage_charge/object/object_storage.h"
#include "storage_charge/core/storage_type.h"
#include "storage_charge/registry/storage_registry.h"

#define BASIC_OBJECT_STORAG_MONTHS 3

static double object_storage_charge(int capacity, int months)
{
    double price = 10;
    if (months > BASIC_OBJECT_STORAG_MONTHS)
    {
        double exceed = months - BASIC_OBJECT_STORAG_MONTHS;
        price += exceed * capacity * 1.5;
    }
    return price;
}

#define MONTHS_OF_YEAR 12

static int object_storage_level(int months)
{
    return months > MONTHS_OF_YEAR ? 1 : 0;
}

static void object_storage_install(StorageBase* storage)
{
    storage->charge = object_storage_charge;
    storage->level  = object_storage_level;
}

void object_storage_register()
{
    object_storage_register_with_type(ST_OBJECT_STORAGE);
}

void object_storage_register_with_type(StorageType type)
{
    storage_registry_register(type, object_storage_install);
}
