cmake_minimum_required(VERSION 3.12 FATAL_ERROR)
project(calc)

# creating the library
add_library(maths adder.cpp)

# handles the "Static vs Dynamic" switch
if(NOT BUILD_SHARED_LIBS)
    add_definitions(-Dmaths_STATIC)
endif()

# creates the executable
add_executable(calc calc.cpp)

# links them together
target_link_libraries(calc maths)