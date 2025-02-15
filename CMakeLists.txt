cmake_minimum_required(VERSION 3.10)
project(RollerCoaster)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(GTest REQUIRED)

add_library(hill_detection_lib
        src/hillsFinder.cpp
        src/hillsFinder.h
)

add_executable(main
        src/main.cpp
)
target_link_libraries(main hill_detection_lib)

add_executable(tests tests/tests.cpp
)
target_link_libraries(tests
        PRIVATE
        hill_detection_lib
        GTest::GTest
        GTest::Main
)

enable_testing()
add_test(NAME HillDetectionTests COMMAND tests)
