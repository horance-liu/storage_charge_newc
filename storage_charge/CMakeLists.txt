file(GLOB_RECURSE all_tests
    *_test.cpp
    *_test.cc
    *_test.c++
)

file(GLOB_RECURSE all_srcs
    *.cpp
    *.cc
    *.c++
    *.c
    *.C
)

list(REMOVE_ITEM all_srcs ${all_tests})
add_library(storage_charge STATIC ${all_srcs})

add_executable(test_storage_charge ${all_tests})
target_link_libraries(test_storage_charge storage_charge gtest gtest_main)

add_test(NAME test_storage_charge COMMAND test_storage_charge)
