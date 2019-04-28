cmake_minimum_required(VERSION 3.11.4)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
include_directories(../src/mhttp)
link_libraries(/usr/local/lib/libgtest.a /usr/local/lib/libgtest_main.a)


file(GLOB SOURCE_FILES ../src/mhttp/*.c ../src/mhttp/*.cxx ../src/mhttp/*.h *.cxx *.h)

add_executable(mhttp-test ${SOURCE_FILES})
