add_executable(C10 main.c)
target_compile_features(C10 PRIVATE c_std_11)
target_link_libraries(C10 PRIVATE common_warnings)
