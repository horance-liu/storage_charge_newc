#include "gtest/gtest.h"
#include "storage_charge/core/storage.h"
#include "storage_charge/core/lease.h"
#include "storage_charge/core/tenant.h"
#include "storage_charge/block/block_storage.h"
#include "storage_charge/file/file_storage.h"
#include "storage_charge/object/object_storage.h"
#include "storage_charge/registry/storage_registry.h"

namespace 
{
/**
 * 存储资源类型
 * */
typedef enum AllStorageType
{
    ST_BLOCK_STORAGE,  /* 块存储 */
    ST_FILE_STORAGE,   /* 文件存储 */
    ST_OBJECT_STORAGE, /* 对象存储 */
    MAX_STORAGE_TYPE,
} AllStorageType;

struct StorageTest : testing::Test
{
private:
    void SetUp() override
    {
        storage_registry_init(MAX_STORAGE_TYPE);
        object_storage_register(ST_OBJECT_STORAGE);
        file_storage_register(ST_FILE_STORAGE);
        block_storage_register(ST_BLOCK_STORAGE);
    }

    void TearDown() override
    {
        storage_registry_destroy();
    }

protected:
    Storage s1{1024, ST_BLOCK_STORAGE};
    Storage s2{512, ST_FILE_STORAGE};
    Storage s3{128, ST_OBJECT_STORAGE};

    Lease l1{3,  &s1};
    Lease l2{4,  &s2};
    Lease l3{14, &s3};
};

TEST_F(StorageTest, total_price_and_levels_for_tenant)
{
    Tenant tenant;
    tenant_init(&tenant);

    tenant_add(&tenant, &l1);
    tenant_add(&tenant, &l2);
    tenant_add(&tenant, &l3);

    double total = 0.0;
    int levels = 0;
    tenant_charge(&tenant, &total, &levels);

    ASSERT_EQ(2185.0, total);
    ASSERT_EQ(1, levels);
}

} // namespace

