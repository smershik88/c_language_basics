add_executable(F2 main.c)
target_compile_features(F2 PRIVATE c_std_11)
target_link_libraries(F2 PRIVATE common_warnings)