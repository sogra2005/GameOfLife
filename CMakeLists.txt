cmake_minimum_required(VERSION 3.23)
project(GameOfLife)

set(CMAKE_CXX_STANDARD 14)

add_executable(GameOfLife main.cpp CellOfLife.cpp CellOfLife.hpp ConsoleMenu.cpp ConsoleMenu.hpp FieldAnalyzer.cpp FieldAnalyzer.hpp FieldLoader.cpp FieldLoader.hpp GameController.cpp GameController.hpp Randomizer.cpp Randomizer.hpp ShowManager.cpp ShowManager.hpp termcolor.hpp)
