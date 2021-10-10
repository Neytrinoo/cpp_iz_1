cmake_minimum_required(VERSION 3.16)
project(cpp_iz_1)

add_compile_options("--coverage")

#set(CMAKE_CXX_FLAGS "-fprofile-arcs -ftest-coverage -fPIC -O0")
#set(CMAKE_C_FLAGS "-fprofile-arcs -ftest-coverage -fPIC -O0")
#set(CMAKE_EXE_LINKER_FLAGS "-fprofile-arcs -ftest-coverage -fPIC -O0")

set(SOURCE_LIB src/into_roman_nums.c src/io_functions.c src/print_errors.c)
set(SOURCE_MAIN_EXE src/main.c)
set(SOURCE_TEST_EXE unit_tests/main.cpp)


add_library(roman_nums STATIC ${SOURCE_LIB})
target_include_directories(roman_nums PUBLIC include)

add_executable(main ${SOURCE_MAIN_EXE})
target_include_directories(main PUBLIC include)
target_link_libraries(main roman_nums gcov)

find_package(GTest REQUIRED)
find_package(Threads REQUIRED)

add_executable(unit_test unit_tests/main.cpp)
target_include_directories(unit_test PUBLIC include)
target_link_libraries(unit_test roman_nums ${GTEST_LIBRARIES} Threads::Threads gcov)