add_executable(D5 main.c)
target_compile_features(D5 PRIVATE c_std_11)
target_link_libraries(D5 PRIVATE common_warnings)