add_executable(B10 main.c)
target_compile_features(B10 PRIVATE c_std_11)
target_link_libraries(B10 PRIVATE common_warnings)
