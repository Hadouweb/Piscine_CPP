cmake_minimum_required(VERSION 3.0)
project(Piscine_CPP)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
	D04/ex00/main.cpp
	D04/ex00/Peon.cpp
	D04/ex00/Peon.hpp
	D04/ex00/Sorcerer.cpp
	D04/ex00/Sorcerer.hpp
	D04/ex00/Victim.cpp
	D04/ex00/Victim.hpp
        )

add_executable(foo ${SOURCE_FILES})