add_executable(C19 main.c)
target_compile_features(C19 PRIVATE c_std_11)
target_link_libraries(C19 PRIVATE common_warnings)
