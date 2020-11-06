cmake_minimum_required(VERSION 3.15)
project(gc C)

set(CMAKE_C_STANDARD 99)

set(GCC_COVERAGE_COMPILE_FLAGS "-O3")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}" )


add_executable(gc main.c stackStructure.h virtualMachine.h torusStructure.h heapStructure.h heap_gc_func.c stack_func.c vm.c torus_func.c)