add_executable(B20 main.c)
target_compile_features(B20 PRIVATE c_std_11)
target_link_libraries(B20 PRIVATE common_warnings)
