
cmake_minimum_required(VERSION 3.20)

project(lazy_cats_stl)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")


if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_definitions(-DDEBUG)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O0")
else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3")
endif()

option(ENABLE_MULTITHREAD "Enable multithread" ON)

if (ENABLE_MULTITHREAD)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")
endif()

set(FETCHCONTENT_BASE_DIR ${CMAKE_SOURCE_DIR}/third-party)

include(FetchContent)

include_directories(${CMAKE_SOURCE_DIR}/include)

option(ENABLE_BASE_TEST "Enable base test" OFF)

if (ENABLE_BASE_TEST)
    enable_testing()
    add_subdirectory(test)
else()
    message(STATUS "Base test is disabled")
    add_subdirectory(src)
endif()
