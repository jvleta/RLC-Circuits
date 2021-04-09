cmake_minimum_required (VERSION 3.2)
project(CATs)

set(gtest_disable_pthreads ON)
set(gtest_force_shared_crt ON)
add_subdirectory(external/googletest)
set(gtest_disable_pthreads OFF)
set(gtest_force_shared_crt OFF)

add_subdirectory(external/rapidjson)
include_directories(src external/rapidjson/include external/googletest/googletest/include)
# add_subdirectory(src)
add_subdirectory(tests)