cmake_minimum_required(VERSION 3.20)
project(lab1)

include_directories (include)
set(SRC main.cpp Counter.cpp)

add_executable(lab1 main.cpp counter.cpp counter.h)
