cmake_minimum_required(VERSION 3.6)
project(Dissertation)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11")
add_subdirectory(lib/googletest-master)

include_directories(lib/googletest-master/googletest/include)

include_directories(lib/googletest-master/googlemock/include)


set(SOURCE_FILES main.cpp Electron.h Electron.cpp Trap.cpp Trap.h Functions.cpp Functions.h ElectronHole.cpp ElectronHole.h Crystal.cpp Crystal.h tests/test.h)
add_executable(Dissertation ${SOURCE_FILES} tests/test.h)
target_link_libraries(Dissertation gtest gtest_main)