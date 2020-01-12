set(storage_core_libs storage_core storage_registry)
set(storage_test_libs ${storage_core_libs} gtest gtest_main)

add_subdirectory("core")
add_subdirectory("registry")

add_subdirectory("block")
add_subdirectory("file")
add_subdirectory("object")

add_subdirectory("test_all")
add_subdirectory("test_single")