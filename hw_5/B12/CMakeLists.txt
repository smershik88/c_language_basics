add_executable(B12 main.c)
target_compile_features(B12 PRIVATE c_std_11)
target_link_libraries(B12 PRIVATE common_warnings)
