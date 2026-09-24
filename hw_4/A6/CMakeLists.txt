cmake_minimum_required(VERSION 3.10.0)
project(A6 VERSION 0.1.0 LANGUAGES C)

add_executable(A6 main.c)
target_compile_features(A6 PRIVATE c_std_11)
target_link_libraries(A6 PRIVATE common_warnings)
