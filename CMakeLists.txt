cmake_minimum_required(VERSION 4.0)
project(MIME_OS)

set(CMAKE_CXX_STANDARD 20)

add_executable(MIME_OS src/main.cpp
        src/kernel/process/Process.cpp
        include/Process.hpp
        src/kernel/process/PCB.cpp
        include/PCB.hpp
        tests/test_process.cpp
        src/kernel/logging/Logger.cpp
        include/kernel/logging/Logger.hpp
        include/utils/StringUtils.hpp
        src/utils/StringUtils.cpp
        src/shell/Commands.cpp
        src/shell/Commands.cpp
        include/shell/Shell.hpp
        src/shell/Shell.cpp
        include/fileSystem/FSNode.hpp
        include/fileSystem/Directory.hpp
        include/fileSystem/File.hpp
        src/kernel/filesystem/File.cpp)

