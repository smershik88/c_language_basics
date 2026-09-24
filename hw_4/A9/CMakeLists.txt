cmake_minimum_required(VERSION 3.10.0)
project(A9 VERSION 0.1.0 LANGUAGES C)

add_executable(A9 main.c)
target_compile_features(A9 PRIVATE c_std_11)
target_link_libraries(A9 PRIVATE common_warnings)
