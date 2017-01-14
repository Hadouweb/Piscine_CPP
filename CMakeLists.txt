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
	D04/ex01/AWeapon.hpp
	D04/ex01/Character.hpp
	D04/ex01/Enemy.hpp
	D04/ex01/PlasmaRifle.hpp
	D04/ex01/PowerFist.hpp
	D04/ex01/RadScorpion.hpp
	D04/ex01/SuperMutant.hpp
	D04/ex01/AWeapon.cpp
	D04/ex01/Character.cpp
	D04/ex01/Enemy.cpp
	D04/ex01/PlasmaRifle.cpp
	D04/ex01/PowerFist.cpp
	D04/ex01/RadScorpion.cpp
	D04/ex01/SuperMutant.cpp
	D04/ex01/main.cpp
	D04/ex02/AssaultTerminator.cpp
	D04/ex02/AssaultTerminator.hpp
	D04/ex02/ISpaceMarine.hpp
	D04/ex02/ISquad.hpp
	D04/ex02/main.cpp
	D04/ex02/Squad.cpp
	D04/ex02/Squad.hpp
	D04/ex02/TacticalMarine.cpp
	D04/ex02/TacticalMarine.hpp
        )

add_executable(foo ${SOURCE_FILES})