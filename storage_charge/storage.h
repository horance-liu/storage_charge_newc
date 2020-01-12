#ifndef HAC6DA0FC_9308_4D5E_913B_AF818970CE7D
#define HAC6DA0FC_9308_4D5E_913B_AF818970CE7D

#include "storage_charge/storage_type.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * 存储资源
 * */
typedef struct StorageTag
{
    int capacity;     /* 存储容量，单位: MB */
    StorageType type; /* 存储类型 */
} Storage;

double storage_charge(const Storage* storage, int months);
int storage_level(const Storage* storage, int months);

#ifdef __cplusplus
}
#endif

#endif /* HAC6DA0FC_9308_4D5E_913B_AF818970CE7D */
