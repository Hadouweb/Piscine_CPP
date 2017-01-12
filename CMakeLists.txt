cmake_minimum_required(VERSION 3.0)
project(Piscine_CPP)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
        D03/ex01/FragTrap.hpp
        D03/ex01/FragTrap.cpp
        D03/ex01/ScavTrap.hpp
        D03/ex01/ScavTrap.cpp
        D03/ex01/main.cpp
        )

add_executable(foo ${SOURCE_FILES})