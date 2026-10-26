cmake_minimum_required(VERSION 3.10.0)
project(E15 VERSION 0.1.0 LANGUAGES C)

add_executable(E15 main.c)
target_compile_features(E15 PRIVATE c_std_11)
target_link_libraries(E15 PRIVATE common_warnings)