file(GLOB all_tests
    *_test.cpp
    *_test.cc
    *_test.c++
)

add_executable(test_storage_all ${all_tests})
target_link_libraries(test_storage_all block_storage file_storage object_storage ${storage_test_libs})

add_test(NAME test_storage_all COMMAND test_storage_all)