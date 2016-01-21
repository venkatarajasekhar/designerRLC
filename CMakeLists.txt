cmake_minimum_required(VERSION 3.2)
project(designerRLC)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp
        Variables.cpp Variables.h
        Expression.cpp Expression.h
        AST.cpp AST.cpp AST.h PolishNotation.cpp PolishNotation.h)
add_executable(designerRLC ${SOURCE_FILES})