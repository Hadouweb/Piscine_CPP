cmake_minimum_required(VERSION 3.0)
project(Piscine_CPP)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
        D03/ex04/FragTrap.hpp
        D03/ex04/FragTrap.cpp
        D03/ex04/ScavTrap.hpp
        D03/ex04/ScavTrap.cpp
        D03/ex04/ClapTrap.cpp
        D03/ex04/ClapTrap.hpp
        D03/ex04/NinjaTrap.hpp
        D03/ex04/NinjaTrap.cpp
        D03/ex04/SuperTrap.cpp
        D03/ex04/SuperTrap.hpp
        D03/ex04/main.cpp
        )

add_executable(foo ${SOURCE_FILES})