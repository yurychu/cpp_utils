cmake_minimum_required(VERSION 3.9)
project(circular_balancing_buffer)


set(CMAKE_CXX_STANDARD 14)
set(CMAKE_BUILD_TYPE Debug)

set(SOURCE_HEADERS
        CircularBalancingBuffer.hpp
        )


set(SOURCE_EXE
        main.cpp
        ${SOURCE_HEADERS}
        )

add_executable(
        main
        ${SOURCE_EXE}
)