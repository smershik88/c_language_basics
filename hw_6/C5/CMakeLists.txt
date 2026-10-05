cmake_minimum_required(VERSION 3.10.0)
project(C5 VERSION 0.1.0 LANGUAGES C)

add_executable(C5 main.c)
target_compile_features(C5 PRIVATE c_std_11)
target_link_libraries(C5 PRIVATE common_warnings)
