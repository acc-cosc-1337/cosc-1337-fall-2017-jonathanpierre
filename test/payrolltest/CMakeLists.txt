include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(payrollTests payroll_test.cpp)

target_link_libraries(payrollTests gtest gtest_main)
target_link_libraries(payrollTests payroll_library)
