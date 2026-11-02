add_executable(F9 main.c)
target_compile_features(F9 PRIVATE c_std_11)
target_link_libraries(F9 PRIVATE common_warnings)