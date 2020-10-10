cmake_minimum_required(VERSION 3.16)
project(pylsbn)

set(CMAKE_CXX_STANDARD 14)
set(PYBIND11_CPP_STANDARD -std=c++14)

include_directories(include)

add_subdirectory(pybind11)
pybind11_add_module(
    clazz
        src/clazz.cpp
        src/binding.cpp
)
