cmake_minimum_required(VERSION 3.10.0)
project(C1 VERSION 0.1.0 LANGUAGES C)

add_executable(C1 main.c)
target_compile_features(C1 PRIVATE c_std_11)
target_link_libraries(C1 PRIVATE common_warnings)
