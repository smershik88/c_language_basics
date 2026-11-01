add_executable(C12 main.c)
target_compile_features(C12 PRIVATE c_std_11)
target_link_libraries(C12 PRIVATE common_warnings)
