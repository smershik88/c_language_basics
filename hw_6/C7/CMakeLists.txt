cmake_minimum_required(VERSION 3.10.0)
project(C7 VERSION 0.1.0 LANGUAGES C)

add_executable(C7 main.c)
target_compile_features(C7 PRIVATE c_std_11)
target_link_libraries(C7 PRIVATE common_warnings)
