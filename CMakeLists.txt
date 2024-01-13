cmake_minimum_required(VERSION 3.26)
project(Timer)

set(CMAKE_CXX_STANDARD 17)

add_executable(Timer main.cpp
        time/Time.cpp
        time/Time.h
        time/DateTime.cpp
        time/DateTime.h
        time/Timer.cpp
        time/Timer.h
        Util.h
        Util.cpp)
