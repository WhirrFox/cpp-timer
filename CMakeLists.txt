cmake_minimum_required(VERSION 3.26)
project(Timer)

set(CMAKE_CXX_STANDARD 17)

add_executable(Timer main.cpp
        Time.cpp
        Time.h
        DateTime.cpp
        DateTime.h
        Timer.cpp
        Timer.h)
