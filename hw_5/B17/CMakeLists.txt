cmake_minimum_required(VERSION 3.10.0)
project(B17 VERSION 0.1.0 LANGUAGES C)

add_executable(B17 main.c)
target_compile_features(B17 PRIVATE c_std_11)
target_link_libraries(B17 PRIVATE common_warnings)
