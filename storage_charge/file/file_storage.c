#include "storage_charge/file/file_storage.h"
#include "storage_charge/core/storage_type.h"
#include "storage_charge/registry/storage_registry.h"

#define BASIC_FILE_STORAGE_MONTHS 2

static double file_storage_charge(int capacity, int months)
{
    double price = 20;
    if (months > BASIC_FILE_STORAGE_MONTHS)
    {
        double exceed = months - BASIC_FILE_STORAGE_MONTHS;
        price += exceed * 1.5;
    }
    return price;
}

static void file_storage_install(StorageBase* storage)
{
    storage->charge = file_storage_charge;
}

void file_storage_register_with_type(StorageType type)
{
    storage_registry_register(type, file_storage_install);
}
