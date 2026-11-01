add_executable(C4 main.c)
target_compile_features(C4 PRIVATE c_std_11)
target_link_libraries(C4 PRIVATE common_warnings)
