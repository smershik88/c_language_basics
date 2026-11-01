add_executable(B2 main.c)
target_compile_features(B2 PRIVATE c_std_11)
target_link_libraries(B2 PRIVATE common_warnings)
