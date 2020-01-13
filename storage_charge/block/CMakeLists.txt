file(GLOB all_srcs
    *.cpp
    *.cc
    *.c++
    *.c
    *.C
)

add_library(block_storage STATIC ${all_srcs})

file(GLOB all_tests
    *_test.cpp
    *_test.cc
    *_test.c++
)

add_executable(test_block_storage ${all_tests})
target_link_libraries(test_block_storage block_storage ${storage_test_libs})

add_test(NAME test_block_storage COMMAND test_block_storage)