file(GLOB all_tests
    *_test.cpp
    *_test.cc
    *_test.c++
)

add_executable(test_storage_single ${all_tests})
target_link_libraries(test_storage_single object_storage ${storage_test_libs})

add_test(NAME test_storage_single COMMAND test_storage_single)