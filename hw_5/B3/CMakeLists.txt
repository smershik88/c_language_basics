add_executable(B3 main.c)
target_compile_features(B3 PRIVATE c_std_11)
target_link_libraries(B3 PRIVATE common_warnings)
