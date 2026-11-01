add_executable(A5 main.c)
target_compile_features(A5 PRIVATE c_std_11)
target_link_libraries(A5 PRIVATE common_warnings)
