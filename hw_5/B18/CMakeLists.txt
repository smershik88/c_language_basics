cmake_minimum_required(VERSION 3.10.0)
project(B18 VERSION 0.1.0 LANGUAGES C)

add_executable(B18 main.c)
target_compile_features(B18 PRIVATE c_std_11)
target_link_libraries(B18 PRIVATE common_warnings)
