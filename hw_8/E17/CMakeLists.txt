add_executable(E17 main.c)
target_compile_features(E17 PRIVATE c_std_11)
target_link_libraries(E17 PRIVATE common_warnings)