cmake_minimum_required(VERSION 3.10.0)
project(A19 VERSION 0.1.0 LANGUAGES C)

add_executable(A19 main.c)
target_compile_features(A19 PRIVATE c_std_11)
target_link_libraries(A19 PRIVATE common_warnings)
