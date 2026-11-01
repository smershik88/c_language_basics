add_executable(D20 main.c)
target_compile_features(D20 PRIVATE c_std_11)
target_link_libraries(D20 PRIVATE common_warnings)