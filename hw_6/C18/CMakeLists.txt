cmake_minimum_required(VERSION 3.10.0)
project(C18 VERSION 0.1.0 LANGUAGES C)

add_executable(C18 main.c)
target_compile_features(C18 PRIVATE c_std_11)
target_link_libraries(C18 PRIVATE common_warnings)
