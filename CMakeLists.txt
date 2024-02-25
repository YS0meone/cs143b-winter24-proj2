cmake_minimum_required(VERSION 3.10)
project("vmm" VERSION 1.0)
add_executable(vmm src/vm_manager.cpp
        src/main.cpp)
