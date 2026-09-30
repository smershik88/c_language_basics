cmake_minimum_required(VERSION 3.10.0)
project(B4 VERSION 0.1.0 LANGUAGES C)

add_executable(B4 main.c)
target_compile_features(B4 PRIVATE c_std_11)
target_link_libraries(B4 PRIVATE common_warnings)
