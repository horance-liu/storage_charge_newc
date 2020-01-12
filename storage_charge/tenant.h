#ifndef HCE627815_E322_4865_8463_CAA81513C14F
#define HCE627815_E322_4865_8463_CAA81513C14F

#ifdef __cplusplus
extern "C" {
#endif

#define MAX_NUM_LEASE  32   /* 每个租户的最大资源租期数 */

/**
 * 存储资源类型
 * */
typedef enum
{
    ST_BLOCK_STORAGE,  /* 块存储 */
    ST_FILE_STORAGE,   /* 文件存储 */
    ST_OBJECT_STORAGE, /* 对象存储 */
} StorageType;

/**
 * 存储资源
 * */
typedef struct StorageTag
{
    int capacity;     /* 存储容量，单位: MB */
    StorageType type; /* 存储类型 */
} Storage;

typedef struct LeaseTag Lease;

/**
 * 租户
 * */
typedef struct TenantTag
{
    int numOfLeases;              /* 租期数目 */
    Lease* leases[MAX_NUM_LEASE]; /* 租期列表 */
} Tenant;

/**
 * 租户计费算法
 * */
void tenant_charge(const Tenant* tenant, double* total, int* levels);

#ifdef __cplusplus
}
#endif

#endif
