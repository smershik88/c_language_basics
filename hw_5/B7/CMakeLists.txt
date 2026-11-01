add_executable(B7 main.c)
target_compile_features(B7 PRIVATE c_std_11)
target_link_libraries(B7 PRIVATE common_warnings)
