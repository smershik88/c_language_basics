add_executable(A11 main.c)
target_compile_features(A11 PRIVATE c_std_11)
target_link_libraries(A11 PRIVATE common_warnings)
