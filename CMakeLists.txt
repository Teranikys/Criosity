cmake_minimum_required(VERSION 3.28)
project(Criosity C)

set(CMAKE_C_STANDARD 11)

add_executable(Criosity main.c
        common.h
        chunk.h
        chunk.c
        memory.h
        memory.c
        debug.h
        debug.c
        value.c
        value.h
        vm.c
        vm.h
)
