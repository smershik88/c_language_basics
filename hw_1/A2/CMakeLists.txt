cmake_minimum_required(VERSION 3.10.0)
project(A2 VERSION 0.1.0 LANGUAGES C)

add_executable(A2 main.c)
target_compile_features(A2 PRIVATE c_std_11)
target_link_libraries(A2 PRIVATE common_warnings)

