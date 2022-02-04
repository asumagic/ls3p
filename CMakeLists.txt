cmake_minimum_required(VERSION 3.16)

project(ls3p LANGUAGES CXX)

add_library(ls3p
    src/jsonrpc.cpp
)

target_include_directories(ls3p PUBLIC
    include/
    lib/nlohmann/include/
)

target_compile_features(ls3p PUBLIC cxx_std_17)

enable_testing()
add_subdirectory(tests)