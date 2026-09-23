cmake_minimum_required(VERSION 3.10.0)
project(c_language_basics VERSION 0.1.0 LANGUAGES C)

add_library(common_warnings INTERFACE)
target_compile_options(common_warnings INTERFACE
    -Wall -Wextra -pedantic
    -Wshadow
    -Wconversion -Wsign-conversion
    -Wstrict-prototypes -Wmissing-prototypes
    -Wold-style-definition
    -Wformat=2
    -Wundef
    -Wpointer-arith
    -Wcast-qual
    -Wwrite-strings
)

add_subdirectory(hw_1 hw_1)
add_subdirectory(hw_2/Task4 hw_2)
add_subdirectory(hw_3 hw_3)