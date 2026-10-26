cmake_minimum_required(VERSION 3.10.0)
project(E14 VERSION 0.1.0 LANGUAGES C)

add_executable(E14 main.c)
target_compile_features(E14 PRIVATE c_std_11)
target_link_libraries(E14 PRIVATE common_warnings)