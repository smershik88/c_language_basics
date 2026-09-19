cmake_minimum_required(VERSION 3.10.0)
project(A0 VERSION 0.1.0 LANGUAGES C)

add_executable(A0 main.c)
target_compile_features(A0 PRIVATE c_std_11)
target_link_libraries(A0 PRIVATE common_warnings)
