add_executable(E10 main.c)
target_compile_features(E10 PRIVATE c_std_11)
target_link_libraries(E10 PRIVATE common_warnings)