cmake_minimum_required(VERSION 3.10.0)
project(A10 VERSION 0.1.0 LANGUAGES C)

add_executable(A10 main.c)
target_compile_features(A10 PRIVATE c_std_11)
target_link_libraries(A10 PRIVATE common_warnings)
