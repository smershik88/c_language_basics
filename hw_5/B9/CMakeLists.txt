cmake_minimum_required(VERSION 3.10.0)
project(B9 VERSION 0.1.0 LANGUAGES C)

add_executable(B9 main.c)
target_compile_features(B9 PRIVATE c_std_11)
target_link_libraries(B9 PRIVATE common_warnings)
