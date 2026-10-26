cmake_minimum_required(VERSION 3.10.0)
project(E3 VERSION 0.1.0 LANGUAGES C)

add_executable(E3 main.c)
target_compile_features(E3 PRIVATE c_std_11)
target_link_libraries(E3 PRIVATE common_warnings)