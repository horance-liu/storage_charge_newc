#include "gtest/gtest.h"
#include "storage_charge/core/storage.h"
#include "storage_charge/core/lease.h"
#include "storage_charge/core/tenant.h"
#include "storage_charge/object/object_storage.h"

namespace 
{

struct StorageTest : testing::Test
{
private:
    void SetUp() override
    {
        object_storage_register();
    }

protected:
    Storage s1{1024, ST_BLOCK_STORAGE};
    Storage s2{512, ST_FILE_STORAGE};
    Storage s3{128, ST_OBJECT_STORAGE};

    Lease l1{3,  &s1};
    Lease l2{4,  &s2};
    Lease l3{14, &s3};
};

TEST_F(StorageTest, total_price_and_levels)
{
    Tenant tenant;

    tenant.numOfLeases = 0;
    tenant.leases[tenant.numOfLeases++] = &l1;
    tenant.leases[tenant.numOfLeases++] = &l2;
    tenant.leases[tenant.numOfLeases++] = &l3;

    double total = 0.0;
    int levels = 0;
    tenant_charge(&tenant, &total, &levels);

    ASSERT_EQ(2185.0, total);
    ASSERT_EQ(1, levels);
}

} // namespace
