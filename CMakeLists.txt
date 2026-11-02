cmake_minimum_required(VERSION 3.21)

project(Nexora VERSION 0.0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

option(NEXORA_BUILD_TESTS "Compilar tests" ON)

add_subdirectory(native/core)

if(NEXORA_BUILD_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()
