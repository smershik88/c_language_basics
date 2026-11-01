add_executable(A12 main.c)
target_compile_features(A12 PRIVATE c_std_11)
target_link_libraries(A12 PRIVATE common_warnings)
