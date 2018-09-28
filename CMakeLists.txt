cmake_minimum_required(VERSION 3.5)

add_compile_options(-Wall -Wno-unused-function)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_BUILD_TYPE Debug)


project(utils)

include_directories(
        ./
)

set(SOURCE_HEADERS
        CircularBalancingBuffer.hpp
        ExperimClass.hpp
        CustomConfParser.hpp
        PipeBox.hpp
        StateTable.hpp
        )

set(SOURCE_EXE
        main.cpp

        ${SOURCE_HEADERS}
        )


add_executable(
        main
        ${SOURCE_EXE}
)