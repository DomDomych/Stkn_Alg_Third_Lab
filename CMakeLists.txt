cmake_minimum_required(VERSION 3.10)

project(third_lab)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(third_lab
    example/main.cpp
    src/queue.cpp
)

target_include_directories(third_lab PRIVATE
    include
)

