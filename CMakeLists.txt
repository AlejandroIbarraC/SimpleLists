cmake_minimum_required(VERSION 3.13)
project(SimpleLists)

set(CMAKE_CXX_STANDARD 14)

add_executable(Lists List/main.cpp List/List.cpp List/List.h List/Collector.cpp List/Collector.h List/Node.cpp List/Node.h "Unit Tests/ListTest.cpp" "Unit Tests/ListTest.h")