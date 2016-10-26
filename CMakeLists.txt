cmake_minimum_required(VERSION 3.6)
project(Dissertation)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Electron.h Electron.cpp Trap.cpp Trap.h Functions.cpp Functions.h ElectronHole.cpp ElectronHole.h Crystal.cpp Crystal.h)
add_executable(Dissertation ${SOURCE_FILES})