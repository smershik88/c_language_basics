cmake_minimum_required(VERSION 3.10.0)
project(D20 VERSION 0.1.0 LANGUAGES C)

add_executable(D20 main.c)
target_compile_features(D20 PRIVATE c_std_11)
target_link_libraries(D20 PRIVATE common_warnings)