cmake_minimum_required(VERSION 3.10.0)
project(D6 VERSION 0.1.0 LANGUAGES C)

add_executable(D6 main.c)
target_compile_features(D6 PRIVATE c_std_11)
target_link_libraries(D6 PRIVATE common_warnings)