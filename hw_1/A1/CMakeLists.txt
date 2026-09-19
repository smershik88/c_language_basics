cmake_minimum_required(VERSION 3.10.0)
project(A1 VERSION 0.1.0 LANGUAGES C)

add_executable(A1 main.c)
target_compile_features(A1 PRIVATE c_std_11)
target_link_libraries(A1 PRIVATE common_warnings)

