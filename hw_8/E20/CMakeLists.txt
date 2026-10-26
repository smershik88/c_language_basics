cmake_minimum_required(VERSION 3.10.0)
project(E20 VERSION 0.1.0 LANGUAGES C)

add_executable(E20 main.c)
target_compile_features(E20 PRIVATE c_std_11)
target_link_libraries(E20 PRIVATE common_warnings)