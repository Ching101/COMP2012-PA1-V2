cmake_minimum_required(VERSION 3.26)
project(COMP2012-PA1)

set(CMAKE_CXX_STANDARD 11)
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address,leak,undefined")
set(CMAKE_CXX_COMPILER "/opt/homebrew/Cellar/llvm@13/13.0.1_2/bin/clang++")

include_directories(include)
add_executable(COMP2012-PA1 main.cpp Column.cpp Table.cpp) #main.cpp => pa1.exe
add_executable(COMP2012-PA1-test main_test.cpp Column.cpp Table.cpp) #main_test.cpp => pa1-test.exe
