cmake_minimum_required(VERSION 3.10.0)
project(B16 VERSION 0.1.0 LANGUAGES C)

add_executable(B16 main.c)
target_compile_features(B16 PRIVATE c_std_11)
target_link_libraries(B16 PRIVATE common_warnings)
