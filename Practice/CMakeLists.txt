cmake_minimum_required(VERSION 3.15)
project(Practice)

set(CMAKE_CXX_STANDARD 17)

add_executable(VariablesAndTypes VariablesAndTypes.cpp)
add_executable(ClassesAndObjects ClassesAndObjects/ClassesAndObjects.cpp ClassesAndObjects/Person.cpp ClassesAndObjects/Person.h)