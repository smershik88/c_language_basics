add_executable(E4 main.c)
target_compile_features(E4 PRIVATE c_std_11)
target_link_libraries(E4 PRIVATE common_warnings)