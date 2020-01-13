#ifndef H9523F021_5F43_4E38_ABED_F858B95921E0
#define H9523F021_5F43_4E38_ABED_F858B95921E0

#include "storage_charge/core/storage_type.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef double (*StorageCharge)(int capacity, int months);
typedef int (*StorageLevel)(int months);

typedef struct StorageBase
{
    StorageCharge charge;
    StorageLevel level;
} StorageBase;

typedef void (*StorageInstall)(StorageBase*);

void storage_registry_init(StorageType size);
void storage_registry_destroy();

void storage_registry_register(StorageType type, StorageInstall install);
StorageBase* storage_registry_find(StorageType type);

#ifdef __cplusplus
}
#endif

#endif /* H9523F021_5F43_4E38_ABED_F858B95921E0 */
