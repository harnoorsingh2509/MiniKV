cmake_minimum_required(VERSION 3.20)

project(MiniKV
    VERSION 1.0.0
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(FetchContent)

FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)

# Storage engine
add_library(minikv_store
    src/store.cpp
)

target_include_directories(minikv_store
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Command-line application
add_executable(minikv
    src/main.cpp
)

target_link_libraries(minikv
    PRIVATE
        minikv_store
)

# Automated tests
enable_testing()

add_executable(minikv_tests
    tests/store_test.cpp
)

target_link_libraries(minikv_tests
    PRIVATE
        minikv_store
        GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(minikv_tests)