cmake_minimum_required(VERSION 3.10.0)
project(E2 VERSION 0.1.0 LANGUAGES C)

add_executable(E2 main.c)
target_compile_features(E2 PRIVATE c_std_11)
target_link_libraries(E2 PRIVATE common_warnings)