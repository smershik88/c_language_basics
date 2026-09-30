cmake_minimum_required(VERSION 3.10.0)
project(B13 VERSION 0.1.0 LANGUAGES C)

add_executable(B13 main.c)
target_compile_features(B13 PRIVATE c_std_11)
target_link_libraries(B13 PRIVATE common_warnings)
