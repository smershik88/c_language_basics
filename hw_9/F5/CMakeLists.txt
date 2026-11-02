add_executable(F5 main.c)
target_compile_features(F5 PRIVATE c_std_11)
target_link_libraries(F5 PRIVATE common_warnings)