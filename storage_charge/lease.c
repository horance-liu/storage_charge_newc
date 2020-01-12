#include "storage_charge/lease.h"
#include "storage_charge/storage.h"

#define BASIC_BLOCK_SIZE 1024 /* 块存储的最大值 */
#define BASIC_FILE_STORAGE_MONTHS 2
#define BASIC_OBJECT_STORAG_MONTHS 3

double lease_charge(const Lease *lease)
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
