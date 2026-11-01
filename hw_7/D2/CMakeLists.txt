add_executable(D2 main.c)
target_compile_features(D2 PRIVATE c_std_11)
target_link_libraries(D2 PRIVATE common_warnings)