cmake_minimum_required(VERSION 3.15)
project(Dziekanat)

set(CMAKE_CXX_STANDARD 14)

add_executable(Dziekanat main.cpp teacher.cpp teacher.h student.cpp student.h course.cpp course.h)