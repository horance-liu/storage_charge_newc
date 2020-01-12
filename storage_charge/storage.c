#include "storage_charge/storage.h"
#include "storage_charge/block/block_storage.h"

#define BASIC_FILE_STORAGE_MONTHS 2
#define BASIC_OBJECT_STORAG_MONTHS 3

static double charge_for_block_storage(int capacity, int months)
{
    return block_storage_charge(capacity, months);
}

static double charge_for_file_storage(int months)
{
    double price = 20;
    if (months > BASIC_FILE_STORAGE_MONTHS)
    {
        double exceed = months - BASIC_FILE_STORAGE_MONTHS;
        price += exceed * 1.5;
    }
    return price;
}

static double charge_for_object_storage(int capacity, int months)
{
    double price = 10;
    if (months > BASIC_OBJECT_STORAG_MONTHS)
    {
        double exceed = months - BASIC_OBJECT_STORAG_MONTHS;
        price += exceed * capacity * 1.5;
    }
    return price;
}

double storage_charge(const Storage* storage, int months)
{
    switch (storage->type)
    {
    case ST_BLOCK_STORAGE:
        return charge_for_block_storage(storage->capacity, months);
    case ST_FILE_STORAGE:
        return charge_for_file_storage(months);
    case ST_OBJECT_STORAGE:
        return charge_for_object_storage(storage->capacity, months);
    default:
        return 0;
    }
}

#define MONTHS_OF_YEAR 12

static int level_for_object_storage(int months)
{
    return months > MONTHS_OF_YEAR ? 1 : 0;
}

int storage_level(const Storage* storage, int months)
{
    if (storage->type == ST_OBJECT_STORAGE)
    {
        return level_for_object_storage(months);
    }
    return 0;
}
