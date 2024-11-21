cmake_minimum_required(VERSION 3.29)
project(PokeDex)

set(CMAKE_CXX_STANDARD 20)

add_executable(PokeDex main.cpp
        Pokedex.cpp
        Pokedex.h
        Pokemon.cpp
        Pokemon.h
        handleMenu.h
        handleMenu.cpp)
