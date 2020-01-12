#include "storage_charge/storage.h"

#define BASIC_BLOCK_SIZE 1024 /* 块存储的最大值 */
#define BASIC_FILE_STORAGE_MONTHS 2
#define BASIC_OBJECT_STORAG_MONTHS 3

double storage_charge(const Storage* storage, int months)
{
    double price = 0;
    switch (storage->type)
    {
    case ST_BLOCK_STORAGE:
        price += 40;
        if (storage->capacity > BASIC_BLOCK_SIZE)
        {
            double exceed = storage->capacity - BASIC_BLOCK_SIZE;
            price += months * exceed * 3;
        }
        break;
    case ST_FILE_STORAGE:
        price += 20;
        if (months > BASIC_FILE_STORAGE_MONTHS)
        {
            double exceed = months - BASIC_FILE_STORAGE_MONTHS;
            price += exceed * 1.5;
        }
        break;
    case ST_OBJECT_STORAGE:
        price += 10;
        if (months > BASIC_OBJECT_STORAG_MONTHS)
        {
            double exceed = months - BASIC_OBJECT_STORAG_MONTHS;
            price += exceed * storage->capacity * 1.5;
        }
        break;
    default:
        break;
    }
    return price;
}
