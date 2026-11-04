add_executable(F12 main.c)
target_compile_features(F12 PRIVATE c_std_11)
target_link_libraries(F12 PRIVATE common_warnings)