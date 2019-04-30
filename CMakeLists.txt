cmake_minimum_required(VERSION 3.13)
project(eurovition C)

set(CMAKE_C_STANDARD 99)

add_executable(eurovition eurovition.c map.c eurovision.h list.h map.h)