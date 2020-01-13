#include "gtest/gtest.h"
#include "storage_charge/core/storage.h"
#include "storage_charge/object/object_storage.h"
#include "storage_charge/registry/storage_registry.h"

namespace
{

typedef enum SingleStorageType
{
    ST_OBJECT_STORAGE,
    MAX_STORAGE_TYPE,
} SingleStorageType;

struct ObjectStorageTest : testing::Test
{
private:
    void SetUp() override
    {
        storage_registry_init(MAX_STORAGE_TYPE);
        object_storage_register(ST_OBJECT_STORAGE);
    }

    void TearDown() override
    {
        storage_registry_destroy();
    }

protected:
    Storage storage{1024, ST_OBJECT_STORAGE};
};

TEST_F(ObjectStorageTest, charge_when_not_greater_than_duration)
{
    ASSERT_DOUBLE_EQ(10.00, storage_charge(&storage, 3));
}

TEST_F(ObjectStorageTest, charge_when_greater_than_duration)
{
    ASSERT_DOUBLE_EQ(1546.00, storage_charge(&storage, 4));
}

TEST_F(ObjectStorageTest, not_allow_upgrade_level)
{
    ASSERT_EQ(0, storage_level(&storage, 12));
}

TEST_F(ObjectStorageTest, allow_upgrade_level)
{
    ASSERT_EQ(1, storage_level(&storage, 13));
}

} // namespace

