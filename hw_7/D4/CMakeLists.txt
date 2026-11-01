add_executable(D4 main.c)
target_compile_features(D4 PRIVATE c_std_11)
target_link_libraries(D4 PRIVATE common_warnings)