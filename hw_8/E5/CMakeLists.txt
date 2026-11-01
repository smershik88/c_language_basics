add_executable(E5 main.c)
target_compile_features(E5 PRIVATE c_std_11)
target_link_libraries(E5 PRIVATE common_warnings)