add_executable(C15 main.c)
target_compile_features(C15 PRIVATE c_std_11)
target_link_libraries(C15 PRIVATE common_warnings)
