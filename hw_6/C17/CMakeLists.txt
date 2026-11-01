add_executable(C17 main.c)
target_compile_features(C17 PRIVATE c_std_11)
target_link_libraries(C17 PRIVATE common_warnings)
