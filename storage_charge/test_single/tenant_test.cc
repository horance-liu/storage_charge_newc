#include "gtest/gtest.h"
#include "storage_charge/core/storage.h"
#include "storage_charge/core/lease.h"
#include "storage_charge/core/tenant.h"
#include "storage_charge/object/object_storage.h"
#include "storage_charge/registry/storage_registry.h"

namespace 
{

struct StorageTest : testing::Test
{
private:
    void SetUp() override
    {
        storage_registry_init();
        object_storage_register();
    }

protected:
    Storage s{128, ST_OBJECT_STORAGE};
    Lease l{13,  &s};
};

TEST_F(StorageTest, total_price_and_levels_for_tenant)
{
    Tenant tenant;
    tenant_init(&tenant);
    tenant_add(&tenant, &l);

    double total = 0.0;
    int levels = 0;
    tenant_charge(&tenant, &total, &levels);

    ASSERT_EQ(1930.0, total);
    ASSERT_EQ(1, levels);
}

} // namespace

