cmake_minimum_required(VERSION 3.10.0)
project(C11 VERSION 0.1.0 LANGUAGES C)

add_executable(C11 main.c)
target_compile_features(C11 PRIVATE c_std_11)
target_link_libraries(C11 PRIVATE common_warnings)
