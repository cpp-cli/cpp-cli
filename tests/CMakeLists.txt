cmake_minimum_required(VERSION 3.21)

Include(FetchContent)

FetchContent_Declare(
    Catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG v3.7.0)
FetchContent_MakeAvailable(Catch2)

add_executable(tests command.cpp)
target_link_libraries(tests PRIVATE cpp_cli::cpp_cli Catch2::Catch2WithMain)

list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/extras)
include(Catch)
catch_discover_tests(tests)