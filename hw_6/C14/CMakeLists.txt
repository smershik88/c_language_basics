cmake_minimum_required(VERSION 3.10.0)
project(C14 VERSION 0.1.0 LANGUAGES C)

add_executable(C14 main.c)
target_compile_features(C14 PRIVATE c_std_11)
target_link_libraries(C14 PRIVATE common_warnings)
