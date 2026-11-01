add_executable(A2 main.c)
target_compile_features(A2 PRIVATE c_std_11)
target_link_libraries(A2 PRIVATE common_warnings)

