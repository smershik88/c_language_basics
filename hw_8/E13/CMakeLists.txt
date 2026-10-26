cmake_minimum_required(VERSION 3.10.0)
project(E13 VERSION 0.1.0 LANGUAGES C)

add_executable(E13 main.c)
target_compile_features(E13 PRIVATE c_std_11)
target_link_libraries(E13 PRIVATE common_warnings)