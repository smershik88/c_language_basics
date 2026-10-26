cmake_minimum_required(VERSION 3.10.0)
project(E10 VERSION 0.1.0 LANGUAGES C)

add_executable(E10 main.c)
target_compile_features(E10 PRIVATE c_std_11)
target_link_libraries(E10 PRIVATE common_warnings)