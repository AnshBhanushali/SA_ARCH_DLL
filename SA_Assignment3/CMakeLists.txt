cmake_minimum_required(VERSION 3.10)
project(SA_Assignment3)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_PREFIX_PATH "/opt/homebrew")

find_package(GTest REQUIRED CONFIG)

add_executable(CartTest
    CartTest.cc
)
target_link_libraries(CartTest
    GTest::gtest
    GTest::gmock
    GTest::gtest_main
    pthread
)
