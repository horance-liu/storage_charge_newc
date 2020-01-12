#include "storage_charge/file/file_storage.h"

#define BASIC_FILE_STORAGE_MONTHS 2

double file_storage_charge(int months)
{
    double price = 20;
    if (months > BASIC_FILE_STORAGE_MONTHS)
    {
        double exceed = months - BASIC_FILE_STORAGE_MONTHS;
        price += exceed * 1.5;
    }
    return price;
}
