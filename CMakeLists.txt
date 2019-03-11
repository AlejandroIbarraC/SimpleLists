cmake_minimum_required(VERSION 3.13)
project(SimpleLists)

set(CMAKE_CXX_STANDARD 14)
add_subdirectory(lib/googletest-master)
include_directories(lib/googletest-master/googletest/include)
include_directories(lib/googletest-master/googlemock/include)

set(SOURCE_FILES main.cpp Tests/SimpleListTest.cpp Tests/SimpleListTest.h)
add_executable(SimpleLists ${SOURCE_FILES})

target_link_libraries(SimpleLists gtest gtest_main)
