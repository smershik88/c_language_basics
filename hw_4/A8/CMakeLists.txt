add_executable(A8 main.c)
target_compile_features(A8 PRIVATE c_std_11)
target_link_libraries(A8 PRIVATE common_warnings)
