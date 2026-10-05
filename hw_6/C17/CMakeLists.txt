cmake_minimum_required(VERSION 3.10.0)
project(C17 VERSION 0.1.0 LANGUAGES C)

add_executable(C17 main.c)
target_compile_features(C17 PRIVATE c_std_11)
target_link_libraries(C17 PRIVATE common_warnings)
