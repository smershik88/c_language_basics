cmake_minimum_required(VERSION 3.10.0)
project(Task4 VERSION 0.1.0 LANGUAGES C)

add_executable(Task4 main.c)
target_compile_features(Task4 PRIVATE c_std_11)
target_link_libraries(Task4 PRIVATE common_warnings)
