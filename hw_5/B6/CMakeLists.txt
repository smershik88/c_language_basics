cmake_minimum_required(VERSION 3.10.0)
project(B6 VERSION 0.1.0 LANGUAGES C)

add_executable(B6 main.c)
target_compile_features(B6 PRIVATE c_std_11)
target_link_libraries(B6 PRIVATE common_warnings)
