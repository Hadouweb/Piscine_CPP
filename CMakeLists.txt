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
        D05/ex03/Bureaucrat.cpp
        D05/ex03/Bureaucrat.hpp
        D05/ex03/Form.hpp
        D05/ex03/Form.cpp
        D05/ex03/Intern.cpp
        D05/ex03/Intern.Hpp
        D05/ex03/main.cpp
        D05/ex03/PresidentialPardonForm.cpp
        D05/ex03/PresidentialPardonForm.hpp
        D05/ex03/RobotomyRequestForm.cpp
        D05/ex03/RobotomyRequestForm.hpp
        D05/ex03/ShrubberyCreationForm.hpp
        D05/ex03/ShrubberyCreationForm.cpp
        D06/ex00/main.cpp
        D06/ex01/main.cpp
        D06/ex02/main.cpp
        D06/ex02/Base.cpp
        D06/ex02/Base.hpp
        D06/ex02/A.hpp
        D06/ex02/B.hpp
        D06/ex02/C.hpp
        D07/ex00/main.cpp
        D07/ex01/iter.cpp
        D07/ex02/main.cpp
		D07/ex02/Array.hpp
		D08/ex00/easyfind.hpp
		D08/ex00/main.cpp
		D08/ex01/main.cpp
		D08/ex01/span.cpp
		D08/ex01/span.hpp
		D08/ex02/main.cpp
		D08/ex02/mutantstack.hpp
		D08/ex02/mutantstack.cpp
        )

add_executable(foo ${SOURCE_FILES})