add_executable(A7 main.c)
target_compile_features(A7 PRIVATE c_std_11)
target_link_libraries(A7 PRIVATE common_warnings)
