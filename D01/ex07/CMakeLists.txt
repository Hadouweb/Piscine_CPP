cmake_minimum_required(VERSION 3.0)
project(Piscine_CPP)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
	main.cpp
	FileManager.cpp
	FileManager.hpp
    )

add_executable(lol ${SOURCE_FILES})