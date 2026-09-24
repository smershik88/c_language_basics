cmake_minimum_required(VERSION 3.10.0)
project(A15 VERSION 0.1.0 LANGUAGES C)

add_executable(A15 main.c)
target_compile_features(A15 PRIVATE c_std_11)
target_link_libraries(A15 PRIVATE common_warnings)
