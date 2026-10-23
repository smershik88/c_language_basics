cmake_minimum_required(VERSION 3.10.0)
project(D13 VERSION 0.1.0 LANGUAGES C)

add_executable(D13 main.c)
target_compile_features(D13 PRIVATE c_std_11)
target_link_libraries(D13 PRIVATE common_warnings)