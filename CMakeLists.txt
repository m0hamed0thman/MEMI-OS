cmake_minimum_required(VERSION 3.20)
project(MIME_OS)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

file(GLOB OS_SOURCES
        "src/kernel/process/*.cpp"
        "src/filesystem/*.cpp"
        "src/utils/*.cpp"
        "src/kernel/shell/*.cpp"
        "src/hardware/*.cpp"
        "src/kernel/logging/*.cpp"
        "src/kernel/memory/*.cpp"
)

add_executable(MIME_OS
        src/main.cpp
        ${OS_SOURCES}
)