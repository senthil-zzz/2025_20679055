cmake_minimum_required(VERSION 3.12 FATAL_ERROR)
project(calc)

# 1. The Code
add_library(maths adder.cpp)

# ADD THIS MISSING BLOCK BACK IN!
if(NOT BUILD_SHARED_LIBS)
    add_definitions(-Dmaths_STATIC)
endif()

add_executable(calc calc.cpp)
target_link_libraries(calc maths)

# 2. The Installer Setup
if(WIN32)
    set(CPACK_GENERATOR "NSIS")
else()
    set(CPACK_GENERATOR "ZIP")
endif()
include(CPack)

install(TARGETS calc maths
    RUNTIME DESTINATION bin
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib/static)