cmake_minimum_required(VERSION 3.10.0)
project(D10 VERSION 0.1.0 LANGUAGES C)

add_executable(D10 main.c)
target_compile_features(D10 PRIVATE c_std_11)
target_link_libraries(D10 PRIVATE common_warnings)