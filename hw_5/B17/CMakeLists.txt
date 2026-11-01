add_executable(B17 main.c)
target_compile_features(B17 PRIVATE c_std_11)
target_link_libraries(B17 PRIVATE common_warnings)
