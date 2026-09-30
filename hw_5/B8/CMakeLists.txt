cmake_minimum_required(VERSION 3.10.0)
project(B8 VERSION 0.1.0 LANGUAGES C)

add_executable(B8 main.c)
target_compile_features(B8 PRIVATE c_std_11)
target_link_libraries(B8 PRIVATE common_warnings)
