add_executable(B1 main.c)
target_compile_features(B1 PRIVATE c_std_11)
target_link_libraries(B1 PRIVATE common_warnings)
