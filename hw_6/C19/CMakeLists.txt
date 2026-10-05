cmake_minimum_required(VERSION 3.10.0)
project(C19 VERSION 0.1.0 LANGUAGES C)

add_executable(C19 main.c)
target_compile_features(C19 PRIVATE c_std_11)
target_link_libraries(C19 PRIVATE common_warnings)
