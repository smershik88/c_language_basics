cmake_minimum_required(VERSION 3.10.0)
project(D7 VERSION 0.1.0 LANGUAGES C)

add_executable(D7 main.c)
target_compile_features(D7 PRIVATE c_std_11)
target_link_libraries(D7 PRIVATE common_warnings)