cmake_minimum_required(VERSION 3.10.0)
project(B3 VERSION 0.1.0 LANGUAGES C)

add_executable(B3 main.c)
target_compile_features(B3 PRIVATE c_std_11)
target_link_libraries(B3 PRIVATE common_warnings)
