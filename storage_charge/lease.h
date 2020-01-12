#ifndef H80651FA6_9F2F_4E32_A8EC_9F5E9FD153A4
#define H80651FA6_9F2F_4E32_A8EC_9F5E9FD153A4

#ifdef __cplusplus
extern "C" {
#endif

typedef struct StorageTag Storage;

/**
 * 租期
 * */
typedef struct LeaseTag
{
    int months;       /* 租期时长 */
    Storage* storage; /* 存储资源 */
} Lease;

double lease_charge(const Lease *lease);

#ifdef __cplusplus
}
#endif

#endif /* H80651FA6_9F2F_4E32_A8EC_9F5E9FD153A4 */
