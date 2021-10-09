cmake_minimum_required(VERSION 3.17)
project(cpp_iz_1 C)

set(CMAKE_C_STANDARD 99)

include_directories(include)
aux_source_directory(src SRC)

add_executable(cpp_iz_1 ${SRC})