cmake_minimum_required(VERSION 3.13)
project(Lists)

set(CMAKE_CXX_STANDARD 14)

add_executable(Lists main.cpp List.cpp List.h Collector.cpp Collector.h Node.cpp Node.h)