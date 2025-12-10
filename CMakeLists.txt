cmake_minimum_required(VERSION 3.20)
project(MIME_OS)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)


set(OS_SOURCES
        src/kernel/process/Process.cpp
        src/kernel/process/ProcessManager.cpp
        src/kernel/process/Scheduler.cpp
        src/kernel/memory/MemoryManager.cpp
        src/kernel/logging/Logger.cpp
        src/kernel/filesystem/File.cpp
        src/kernel/filesystem/Directory.cpp
        src/kernel/filesystem/FileSystem.cpp
        src/utils/StringUtils.cpp
        src/shell/Commands.cpp
        src/shell/Shell.cpp
        src/hardware/RAM.cpp
)


add_executable(MIME_OS
        src/main.cpp
        ${OS_SOURCES}
)


enable_testing()

add_executable(TestRAM
        tests/hardware/test_RAM.cpp
        ${OS_SOURCES}
)

add_test(NAME RAM_Test COMMAND TestRAM)