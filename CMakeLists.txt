cmake_minimum_required(VERSION 3.13)
project(SimpleLists)

set(CMAKE_CXX_STANDARD 14)
add_subdirectory(lib/gtest)
include_directories(lib/gtest/googletest/include)
include_directories(lib/gtest/googlemock/include)

set(SOURCE_FILES main.cpp Tests/SimpleListTest.cpp Tests/SimpleListTest.h)
add_executable(SimpleLists ${SOURCE_FILES})

if (APPLE)
    add_definitions(-DGTEST_USE_OWN_TR1_TUPLE)
    add_definitions(-D__GLIBCXX__)
endif (APPLE)

target_link_libraries(SimpleLists gtest gtest_main)
