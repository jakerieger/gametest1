cmake_minimum_required(VERSION 3.14)
project(gametest1)

set(CMAKE_CXX_STANDARD 20) # Use C++20
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}/inc
)

add_executable(gametest1
        inc/Types.h
        inc/Point.h
        src/Point.cpp
        src/main.cpp
)