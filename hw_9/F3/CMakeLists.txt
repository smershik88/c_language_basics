add_executable(F3 main.c)
target_compile_features(F3 PRIVATE c_std_11)
target_link_libraries(F3 PRIVATE common_warnings)