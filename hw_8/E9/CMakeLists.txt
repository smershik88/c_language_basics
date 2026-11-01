add_executable(E9 main.c)
target_compile_features(E9 PRIVATE c_std_11)
target_link_libraries(E9 PRIVATE common_warnings)