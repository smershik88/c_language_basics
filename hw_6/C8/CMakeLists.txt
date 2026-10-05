cmake_minimum_required(VERSION 3.10.0)
project(C8 VERSION 0.1.0 LANGUAGES C)

add_executable(C8 main.c)
target_compile_features(C8 PRIVATE c_std_11)
target_link_libraries(C8 PRIVATE common_warnings)
