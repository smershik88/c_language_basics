add_executable(A17 main.c)
target_compile_features(A17 PRIVATE c_std_11)
target_link_libraries(A17 PRIVATE common_warnings)
