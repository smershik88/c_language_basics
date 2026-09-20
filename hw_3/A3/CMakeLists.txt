cmake_minimum_required(VERSION 3.10.0)
project(A3 VERSION 0.1.0 LANGUAGES C)

add_executable(A3 main.c)
target_compile_features(A3 PRIVATE c_std_11)
target_link_libraries(A3 PRIVATE common_warnings)
