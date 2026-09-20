cmake_minimum_required(VERSION 3.10.0)
project(A5 VERSION 0.1.0 LANGUAGES C)

add_executable(A5 main.c)
target_compile_features(A5 PRIVATE c_std_11)
target_link_libraries(A5 PRIVATE common_warnings)
