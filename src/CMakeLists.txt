cmake_minimum_required(VERSION 3.11.4)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

include_directories(jtp)
include_directories(jtp/json)

file(GLOB SOURCE_FILES *.cxx jtp/*.c  jtp/*.h jtp/*.cxx jtp/*.h json/*.h)

find_package(Boost COMPONENTS REQUIRED system thread regex)
include_directories(${Boost_INCLUDE_DIRS})

add_executable(jtp_server ${SOURCE_FILES})

target_link_libraries(jtp_server ${Boost_LIBRARIES})
