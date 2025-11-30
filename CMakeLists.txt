cmake_minimum_required(VERSION 4.0)
project(MIME_OS)

set(CMAKE_CXX_STANDARD 20)

add_executable(MIME_OS src/main.cpp
        src/kernel/process/Process.cpp
        include/Process.hpp)

