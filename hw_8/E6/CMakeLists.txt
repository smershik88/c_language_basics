add_executable(E6 main.c)
target_compile_features(E6 PRIVATE c_std_11)
target_link_libraries(E6 PRIVATE common_warnings)