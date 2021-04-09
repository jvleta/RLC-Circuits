cmake_minimum_required (VERSION 3.13)
project(CATs)

include_directories(src /usr/src/googletest/googletest/include)
add_subdirectory(src)
add_subdirectory(tests)