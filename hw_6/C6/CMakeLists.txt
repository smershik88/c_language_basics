cmake_minimum_required(VERSION 3.10.0)
project(C6 VERSION 0.1.0 LANGUAGES C)

add_executable(C6 main.c)
target_compile_features(C6 PRIVATE c_std_11)
target_link_libraries(C6 PRIVATE common_warnings)
