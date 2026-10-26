cmake_minimum_required(VERSION 3.10.0)
project(E11 VERSION 0.1.0 LANGUAGES C)

add_executable(E11 main.c)
target_compile_features(E11 PRIVATE c_std_11)
target_link_libraries(E11 PRIVATE common_warnings)