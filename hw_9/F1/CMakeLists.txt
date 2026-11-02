add_executable(F1 main.c)
target_compile_features(F1 PRIVATE c_std_11)
target_link_libraries(F1 PRIVATE common_warnings)