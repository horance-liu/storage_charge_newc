#include "storage_charge/object/object_storage.h"

#define BASIC_OBJECT_STORAG_MONTHS 3

double object_storage_charge(int capacity, int months)
{
    double price = 10;
    if (months > BASIC_OBJECT_STORAG_MONTHS)
    {
        double exceed = months - BASIC_OBJECT_STORAG_MONTHS;
        price += exceed * capacity * 1.5;
    }
    return price;
}
