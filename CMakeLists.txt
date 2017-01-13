cmake_minimum_required(VERSION 3.0)
project(Piscine_CPP)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
        D03/ex03/FragTrap.hpp
        D03/ex03/FragTrap.cpp
        D03/ex03/ScavTrap.hpp
        D03/ex03/ScavTrap.cpp
        D03/ex03/ClapTrap.cpp
        D03/ex03/ClapTrap.hpp
        D03/ex03/NinjaTrap.hpp
        D03/ex03/NinjaTrap.cpp
        D03/ex03/main.cpp
        )

add_executable(foo ${SOURCE_FILES})