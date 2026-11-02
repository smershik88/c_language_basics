add_executable(F8 main.c)
target_compile_features(F8 PRIVATE c_std_11)
target_link_libraries(F8 PRIVATE common_warnings)