find_package(Catch2 REQUIRED)

add_executable(jsontests
    jsontests/main.cpp
    jsontests/stdtypes.cpp
    jsontests/basemessages.cpp
    jsontests/rpc.cpp
)
target_link_libraries(jsontests ls3p Catch2::Catch2)

include(CTest)
include(Catch)

catch_discover_tests(jsontests)