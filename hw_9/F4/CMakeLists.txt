add_executable(F4 main.c)
target_compile_features(F4 PRIVATE c_std_11)
target_link_libraries(F4 PRIVATE common_warnings)