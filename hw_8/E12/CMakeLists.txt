cmake_minimum_required(VERSION 3.10.0)
project(E12 VERSION 0.1.0 LANGUAGES C)

add_executable(E12 main.c)
target_compile_features(E12 PRIVATE c_std_11)
target_link_libraries(E12 PRIVATE common_warnings)