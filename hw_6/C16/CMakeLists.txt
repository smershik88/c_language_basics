cmake_minimum_required(VERSION 3.10.0)
project(C16 VERSION 0.1.0 LANGUAGES C)

add_executable(C16 main.c)
target_compile_features(C16 PRIVATE c_std_11)
target_link_libraries(C16 PRIVATE common_warnings)
