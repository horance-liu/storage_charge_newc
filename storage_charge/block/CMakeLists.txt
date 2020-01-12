file(GLOB all_srcs
    *.cpp
    *.cc
    *.c++
    *.c
    *.C
)

add_library(block_storage STATIC ${all_srcs})