cmake_minimum_required(VERSION 3.10.0)
project(D12 VERSION 0.1.0 LANGUAGES C)

add_executable(D12 main.c)
target_compile_features(D12 PRIVATE c_std_11)
target_link_libraries(D12 PRIVATE common_warnings)