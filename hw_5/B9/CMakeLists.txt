add_executable(B9 main.c)
target_compile_features(B9 PRIVATE c_std_11)
target_link_libraries(B9 PRIVATE common_warnings)
