#include "gtest/gtest.h"
#include "storage_charge/core/storage.h"
#include "storage_charge/block/block_storage.h"
#include "storage_charge/registry/storage_registry.h"

namespace
{

typedef enum SingleStorageType
{
    ST_BLOCK_STORAGE,
    MAX_STORAGE_TYPE,
} SingleStorageType;

struct BlockStorageTest : testing::Test
{
private:
    void SetUp() override
    {
        storage_registry_init(MAX_STORAGE_TYPE);
        block_storage_register(ST_BLOCK_STORAGE);
    }

    void TearDown() override
    {
        storage_registry_destroy();
    }
};

TEST_F(BlockStorageTest, charge_when_not_greater_than_basic_block_size)
{
    Storage storage{1024, ST_BLOCK_STORAGE};
    ASSERT_DOUBLE_EQ(40.00, storage_charge(&storage, 3));
}

TEST_F(BlockStorageTest, charge_when_greater_than_basic_block_size)
{
    Storage storage{2048, ST_BLOCK_STORAGE};
    ASSERT_DOUBLE_EQ(9256.00, storage_charge(&storage, 3));
}

TEST_F(BlockStorageTest, not_allow_upgrade_level)
{
    Storage storage{2048, ST_BLOCK_STORAGE};
    ASSERT_EQ(0, storage_level(&storage, 3));
}

} // namespace

