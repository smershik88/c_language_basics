cmake_minimum_required(VERSION 3.10.0)
project(A11 VERSION 0.1.0 LANGUAGES C)

add_executable(A11 main.c)
target_compile_features(A11 PRIVATE c_std_11)
target_link_libraries(A11 PRIVATE common_warnings)
