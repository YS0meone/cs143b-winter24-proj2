cmake_minimum_required(VERSION 3.10)
project("vmm" VERSION 1.0)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)

add_executable(vmm src/vm_manager.cpp
        src/main.cpp
        playground/va_translator.cpp)
