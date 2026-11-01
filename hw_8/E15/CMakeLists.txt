add_executable(E15 main.c)
target_compile_features(E15 PRIVATE c_std_11)
target_link_libraries(E15 PRIVATE common_warnings)