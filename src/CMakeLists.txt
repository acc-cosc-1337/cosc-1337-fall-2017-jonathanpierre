project(payroll_library)


set(HEADER_FILES Payroll.h)

set(SOURCE_FILES Payroll.cpp)

add_library(payroll_library ${SOURCE_FILES} ${HEADER_FILES})
