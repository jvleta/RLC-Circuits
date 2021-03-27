find_package(VTK REQUIRED)
include(${VTK_USE_FILE})

add_executable(CATs main.cpp)
target_link_libraries(CATs ${VTK_LIBRARIES})
