file(GLOB all_srcs
    *.cpp
    *.cc
    *.c++
    *.c
    *.C
)

add_library(file_storage STATIC ${all_srcs})

file(GLOB all_tests
    *_test.cpp
    *_test.cc
    *_test.c++
)

add_executable(test_file_storage ${all_tests})
target_link_libraries(test_file_storage file_storage ${storage_test_libs})

add_test(NAME test_file_storage COMMAND test_file_storage)
