cmake_minimum_required(VERSION 3.10.0)
project(D1 VERSION 0.1.0 LANGUAGES C)

add_executable(D1 main.c)
target_compile_features(D1 PRIVATE c_std_11)
target_link_libraries(D1 PRIVATE common_warnings)