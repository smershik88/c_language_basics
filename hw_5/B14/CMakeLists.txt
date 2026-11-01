add_executable(B14 main.c)
target_compile_features(B14 PRIVATE c_std_11)
target_link_libraries(B14 PRIVATE common_warnings)
