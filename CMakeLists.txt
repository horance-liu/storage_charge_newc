cmake_minimum_required(VERSION 3.4)

project(storage_charge)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-invalid-offsetof -g -std=gnu++11")

include_directories(
    "${CMAKE_CURRENT_SOURCE_DIR}"
    "/usr/local/include/"
)

link_directories("/usr/local/lib")

include(CTest)
enable_testing()

add_subdirectory("storage_charge")
