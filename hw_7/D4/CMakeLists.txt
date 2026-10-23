cmake_minimum_required(VERSION 3.10.0)
project(D4 VERSION 0.1.0 LANGUAGES C)

add_executable(D4 main.c)
target_compile_features(D4 PRIVATE c_std_11)
target_link_libraries(D4 PRIVATE common_warnings)