cmake_minimum_required(VERSION 3.10.0)
project(E7 VERSION 0.1.0 LANGUAGES C)

add_executable(E7 main.c)
target_compile_features(E7 PRIVATE c_std_11)
target_link_libraries(E7 PRIVATE common_warnings)