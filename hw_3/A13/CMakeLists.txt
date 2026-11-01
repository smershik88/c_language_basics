add_executable(A13 main.c)
target_compile_features(A13 PRIVATE c_std_11)
target_link_libraries(A13 PRIVATE common_warnings)
