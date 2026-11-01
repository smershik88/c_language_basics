add_executable(D1 main.c)
target_compile_features(D1 PRIVATE c_std_11)
target_link_libraries(D1 PRIVATE common_warnings)