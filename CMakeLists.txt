cmake_minimum_required(VERSION 3.26)
project(COMP2012-PA1)

set(CMAKE_CXX_STANDARD 11)

include_directories(include)
add_executable(COMP2012-PA1 main_test.cpp Column.cpp Table.cpp)
#main.cpp => pa1.exe
#main_test.cpp => main_test.exe
