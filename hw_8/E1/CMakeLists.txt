cmake_minimum_required(VERSION 3.10.0)
project(E1 VERSION 0.1.0 LANGUAGES C)

add_executable(E1 main.c)
target_compile_features(E1 PRIVATE c_std_11)
target_link_libraries(E1 PRIVATE common_warnings)