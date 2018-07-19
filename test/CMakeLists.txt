cmake_minimum_required(VERSION 3.11.4)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

find_package(GTest REQUIRED)

include_directories(${GTEST_INCLUDE_DIRS})
link_libraries(gtest)

file(GLOB SOURCE_FILES *.cxx *.h)

add_executable(mhttp-test ${SOURCE_FILES})
