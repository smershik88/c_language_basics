cmake_minimum_required(VERSION 3.10.0)
project(B21 VERSION 0.1.0 LANGUAGES C)

add_executable(B21 main.c)
target_compile_features(B21 PRIVATE c_std_11)
target_link_libraries(B21 PRIVATE common_warnings)
