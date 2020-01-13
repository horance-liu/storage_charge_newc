#include "gtest/gtest.h"
#include "storage_charge/core/storage.h"
#include "storage_charge/file/file_storage.h"
#include "storage_charge/registry/storage_registry.h"

namespace
{

typedef enum SingleStorageType
{
    ST_FILE_STORAGE,
    MAX_STORAGE_TYPE,
} SingleStorageType;

struct FileStorageTest : testing::Test
{
private:
    void SetUp() override
    {
        storage_registry_init(MAX_STORAGE_TYPE);
        file_storage_register(ST_FILE_STORAGE);
    }

    void TearDown() override
    {
        storage_registry_destroy();
    }

protected:
    Storage storage{1024, ST_FILE_STORAGE};
};

TEST_F(FileStorageTest, charge_when_not_greater_than_duration)
{
    ASSERT_DOUBLE_EQ(20.00, storage_charge(&storage, 2));
}

TEST_F(FileStorageTest, charge_when_greater_than_duration)
{
    ASSERT_DOUBLE_EQ(21.5, storage_charge(&storage, 3));
}

TEST_F(FileStorageTest, not_allow_upgrade_level)
{
    ASSERT_EQ(0, storage_level(&storage, 13));
}

} // namespace

