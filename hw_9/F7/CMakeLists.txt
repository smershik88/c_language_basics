add_executable(F7 main.c)
target_compile_features(F7 PRIVATE c_std_11)
target_link_libraries(F7 PRIVATE common_warnings)