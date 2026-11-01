add_executable(B15 main.c)
target_compile_features(B15 PRIVATE c_std_11)
target_link_libraries(B15 PRIVATE common_warnings)
