cmake_minimum_required(VERSION 3.10.0)
project(B7 VERSION 0.1.0 LANGUAGES C)

add_executable(B7 main.c)
target_compile_features(B7 PRIVATE c_std_11)
target_link_libraries(B7 PRIVATE common_warnings)
