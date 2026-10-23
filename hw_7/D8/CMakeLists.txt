cmake_minimum_required(VERSION 3.10.0)
project(D8 VERSION 0.1.0 LANGUAGES C)

add_executable(D8 main.c)
target_compile_features(D8 PRIVATE c_std_11)
target_link_libraries(D8 PRIVATE common_warnings)