cmake_minimum_required(VERSION 3.2)
project(cosc-1337-hw)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp)

include_directories(src)

add_subdirectory(test)
add_subdirectory(src)

add_executable(main_exe ${SOURCE_FILES})
target_link_libraries(main_exe payroll_library)
