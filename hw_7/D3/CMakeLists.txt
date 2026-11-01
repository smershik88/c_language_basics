add_executable(D3 main.c)
target_compile_features(D3 PRIVATE c_std_11)
target_link_libraries(D3 PRIVATE common_warnings)