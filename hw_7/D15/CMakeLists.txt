add_executable(D15 main.c)
target_compile_features(D15 PRIVATE c_std_11)
target_link_libraries(D15 PRIVATE common_warnings)