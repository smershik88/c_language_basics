add_executable(A16 main.c)
target_compile_features(A16 PRIVATE c_std_11)
target_link_libraries(A16 PRIVATE common_warnings)
