cmake_minimum_required(VERSION 3.10.0)
project(D19 VERSION 0.1.0 LANGUAGES C)

add_executable(D19 main.c)
target_compile_features(D19 PRIVATE c_std_11)
target_link_libraries(D19 PRIVATE common_warnings)