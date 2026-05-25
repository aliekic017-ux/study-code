cmake_minimum_required(VERSION 3.20)

project(gtest_lab LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(CTest)
enable_testing()

add_library(calculator
    src/calculator.cpp
)

target_include_directories(calculator
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

include(FetchContent)

FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.17.0.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)

add_executable(calculator_tests
    tests/calculator_tests.cpp
)

target_link_libraries(calculator_tests
    PRIVATE
        calculator
        GTest::gtest_main
)

include(GoogleTest)

gtest_discover_tests(calculator_tests)