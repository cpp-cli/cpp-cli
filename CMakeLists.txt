cmake_minimum_required(VERSION 3.21)
project(cpp_cli)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(src)

if(NOT PROJECT_IS_TOP_LEVEL)
    return()
endif()

include(CTest)

add_subdirectory(tests)