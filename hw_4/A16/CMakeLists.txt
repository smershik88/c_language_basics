cmake_minimum_required(VERSION 3.10.0)
project(A16 VERSION 0.1.0 LANGUAGES C)

add_executable(A16 main.c)
target_compile_features(A16 PRIVATE c_std_11)
target_link_libraries(A16 PRIVATE common_warnings)
