#ifndef H9523F021_5F43_4E38_ABED_F858B95921E0
#define H9523F021_5F43_4E38_ABED_F858B95921E0

#include "storage_charge/storage.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef double (*StorageCharge)(int capacity, int months);

StorageCharge create_storage_charge_with_type(StorageType type);

#ifdef __cplusplus
}
#endif

#endif /* H9523F021_5F43_4E38_ABED_F858B95921E0 */
