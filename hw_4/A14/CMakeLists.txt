cmake_minimum_required(VERSION 3.10.0)
project(A14 VERSION 0.1.0 LANGUAGES C)

add_executable(A14 main.c)
target_compile_features(A14 PRIVATE c_std_11)
target_link_libraries(A14 PRIVATE common_warnings)
