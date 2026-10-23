cmake_minimum_required(VERSION 3.10.0)
project(D16 VERSION 0.1.0 LANGUAGES C)

add_executable(D16 main.c)
target_compile_features(D16 PRIVATE c_std_11)
target_link_libraries(D16 PRIVATE common_warnings)