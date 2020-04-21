cmake_minimum_required(VERSION 3.15)
project(SortStation)

set(CMAKE_CXX_STANDARD 14)

file(GLOB Structures
        "./Queue/*.h"
        "./Queue/*.cpp"
        "./Stack/*.cpp"
        "./Stack/*.h"
        "./Vector/*.cpp"
        "./Vector/*.h"
        "./LinkedList ZRL/*.cpp"
        "./LinkedList ZRL/*.h"
        "TwoLinkedList/*.cpp"
        "TwoLinkedList/*.h"
        )
add_executable(SortStation
        main.cpp
        ${Structures}
        GeneralToken.h NumToken.cpp NumToken.h OperatorToken.cpp OperatorToken.h Brackets.cpp Brackets.h SortStationFunctions.h SortStationFunctions.cpp)