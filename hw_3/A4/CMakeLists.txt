cmake_minimum_required(VERSION 3.10.0)
project(A4 VERSION 0.1.0 LANGUAGES C)

add_executable(A4 main.c)
target_compile_features(A4 PRIVATE c_std_11)
target_link_libraries(A4 PRIVATE common_warnings)
