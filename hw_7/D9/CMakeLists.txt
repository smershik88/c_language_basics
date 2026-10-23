cmake_minimum_required(VERSION 3.10.0)
project(D9 VERSION 0.1.0 LANGUAGES C)

add_executable(D9 main.c)
target_compile_features(D9 PRIVATE c_std_11)
target_link_libraries(D9 PRIVATE common_warnings)