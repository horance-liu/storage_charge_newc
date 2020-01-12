#include "storage_charge/block/block_storage.h"

#define BASIC_BLOCK_SIZE 1024 /* 块存储的最大值 */

double block_storage_charge(int capacity, int months)
{
    double price = 40;
    if (capacity > BASIC_BLOCK_SIZE)
    {
        double exceed = capacity - BASIC_BLOCK_SIZE;
        price += months * exceed * 3;
    }
    return price;
}
