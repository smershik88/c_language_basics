add_executable(F11 main.c)
target_compile_features(F11 PRIVATE c_std_11)
target_link_libraries(F11 PRIVATE common_warnings)