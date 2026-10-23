cmake_minimum_required(VERSION 3.10.0)
project(D17 VERSION 0.1.0 LANGUAGES C)

add_executable(D17 main.c)
target_compile_features(D17 PRIVATE c_std_11)
target_link_libraries(D17 PRIVATE common_warnings)