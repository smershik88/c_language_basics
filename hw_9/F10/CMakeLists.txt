add_executable(F10 main.c)
target_compile_features(F10 PRIVATE c_std_11)
target_link_libraries(F10 PRIVATE common_warnings)