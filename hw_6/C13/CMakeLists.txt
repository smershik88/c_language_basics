cmake_minimum_required(VERSION 3.10.0)
project(C13 VERSION 0.1.0 LANGUAGES C)

add_executable(C13 main.c)
target_compile_features(C13 PRIVATE c_std_11)
target_link_libraries(C13 PRIVATE common_warnings)
