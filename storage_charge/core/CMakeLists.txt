file(GLOB all_srcs
    *.cpp
    *.cc
    *.c++
    *.c
    *.C
)

add_library(storage_core STATIC ${all_srcs})