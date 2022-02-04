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

add_executable(rpctest examples/rpc/main.cpp)
target_link_libraries(rpctest PRIVATE ls3p)

find_package(Catch2 REQUIRED)

add_executable(jsontests
    tests/jsontests/main.cpp
    tests/jsontests/stdtypes.cpp
    tests/jsontests/basemessages.cpp
)
target_link_libraries(jsontests ls3p Catch2::Catch2)

include(CTest)
include(Catch)
catch_discover_tests(jsontests)