cmake_minimum_required(VERSION 3.0)
project(Piscine_CPP)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include_directories(rush00/headers)

set(SOURCE_FILES
        rush00/headers/NcurseManager.hpp
        rush00/headers/GameEngine.hpp
        rush00/headers/GameManager.hpp
        rush00/headers/IEntity.hpp
        rush00/headers/Bullet.hpp
        rush00/headers/Player.hpp
        rush00/headers/Enemy.hpp
        rush00/srcs/NcurseManager.cpp
        rush00/srcs/GameEngine.cpp
        rush00/srcs/GameManager.cpp
        rush00/srcs/Bullet.cpp
        rush00/srcs/Player.cpp
        rush00/srcs/Enemy.cpp
        rush00/srcs/main.cpp
        D05/ex01/Bureaucrat.cpp
        D05/ex01/Bureaucrat.hpp
        D05/ex01/Form.hpp
        D05/ex01/Form.cpp
        D05/ex01/main.cpp
        )

add_executable(foo ${SOURCE_FILES})