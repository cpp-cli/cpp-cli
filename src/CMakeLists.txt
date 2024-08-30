add_library(cpp_cli cpp_cli.cpp)

add_library(cpp_cli::cpp_cli ALIAS cpp_cli)

target_include_directories(cpp_cli PUBLIC
    $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
    $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}/include>)