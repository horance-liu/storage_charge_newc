#ifndef HCE627815_E322_4865_8463_CAA81513C14F
#define HCE627815_E322_4865_8463_CAA81513C14F

#ifdef __cplusplus
extern "C" {
#endif

#define MAX_NUM_LEASE  32   /* 每个租户的最大资源租期数 */

typedef struct LeaseTag Lease;

/**
 * 租户
 * */
typedef struct TenantTag
{
    int numOfLeases;              /* 租期数目 */
    Lease* leases[MAX_NUM_LEASE]; /* 租期列表 */
} Tenant;


void tenant_init(Tenant* tenant);
void tenant_add(Tenant* tenant, Lease* lease);
void tenant_charge(const Tenant* tenant, double* total, int* levels);

#ifdef __cplusplus
}
#endif

#endif
