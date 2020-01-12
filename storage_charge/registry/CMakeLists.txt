file(GLOB all_srcs
    *.cpp
    *.cc
    *.c++
    *.c
    *.C
)

add_library(storage_registry STATIC ${all_srcs})