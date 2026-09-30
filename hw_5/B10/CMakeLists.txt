cmake_minimum_required(VERSION 3.10.0)
project(B10 VERSION 0.1.0 LANGUAGES C)

add_executable(B10 main.c)
target_compile_features(B10 PRIVATE c_std_11)
target_link_libraries(B10 PRIVATE common_warnings)
