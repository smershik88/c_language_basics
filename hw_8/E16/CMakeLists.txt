cmake_minimum_required(VERSION 3.10.0)
project(E16 VERSION 0.1.0 LANGUAGES C)

add_executable(E16 main.c)
target_compile_features(E16 PRIVATE c_std_11)
target_link_libraries(E16 PRIVATE common_warnings)