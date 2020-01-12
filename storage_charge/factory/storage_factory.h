#ifndef H9523F021_5F43_4E38_ABED_F858B95921E0
#define H9523F021_5F43_4E38_ABED_F858B95921E0

#include "storage_charge/core/storage_type.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef double (*StorageCharge)(int capacity, int months);
typedef int (*StorageLevel)(int months);

StorageCharge create_storage_charge(StorageType type);
StorageLevel create_storage_level(StorageType type);

void storage_register(StorageType type, StorageCharge, StorageLevel);

#ifdef __cplusplus
}
#endif

#endif /* H9523F021_5F43_4E38_ABED_F858B95921E0 */
