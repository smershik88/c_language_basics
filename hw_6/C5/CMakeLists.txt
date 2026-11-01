add_executable(C5 main.c)
target_compile_features(C5 PRIVATE c_std_11)
target_link_libraries(C5 PRIVATE common_warnings)
