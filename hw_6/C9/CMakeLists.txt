add_executable(C9 main.c)
target_compile_features(C9 PRIVATE c_std_11)
target_link_libraries(C9 PRIVATE common_warnings)
