add_executable(F6 main.c)
target_compile_features(F6 PRIVATE c_std_11)
target_link_libraries(F6 PRIVATE common_warnings)