cmake_minimum_required(VERSION 3.10.0)
project(B19 VERSION 0.1.0 LANGUAGES C)

add_executable(B19 main.c)
target_compile_features(B19 PRIVATE c_std_11)
target_link_libraries(B19 PRIVATE common_warnings)
