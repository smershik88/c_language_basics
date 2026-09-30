cmake_minimum_required(VERSION 3.10.0)
project(B11 VERSION 0.1.0 LANGUAGES C)

add_executable(B11 main.c)
target_compile_features(B11 PRIVATE c_std_11)
target_link_libraries(B11 PRIVATE common_warnings)
