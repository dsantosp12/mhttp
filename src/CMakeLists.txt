cmake_minimum_required(VERSION 3.11.4)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

include_directories(mhttp)
file(GLOB SOURCE_FILES *.cxx mhttp/*.c  mhttp/*.h mhttp/*.cxx mhttp/*.h)

find_package(Boost COMPONENTS REQUIRED system thread regex)
include_directories(${Boost_INCLUDE_DIRS})

add_executable(mhttp ${SOURCE_FILES})

target_link_libraries(mhttp ${Boost_LIBRARIES})
