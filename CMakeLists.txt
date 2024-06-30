cmake_minimum_required(VERSION 3.0)

project(snake)

add_executable(snake main.cpp)

install(TARGETS snake RUNTIME DESTINATION bin)
