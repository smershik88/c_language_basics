add_executable(E13 main.c)
target_compile_features(E13 PRIVATE c_std_11)
target_link_libraries(E13 PRIVATE common_warnings)