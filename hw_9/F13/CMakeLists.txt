add_executable(F13 main.c)
target_compile_features(F13 PRIVATE c_std_11)
target_link_libraries(F13 PRIVATE common_warnings)