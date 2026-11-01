add_executable(E12 main.c)
target_compile_features(E12 PRIVATE c_std_11)
target_link_libraries(E12 PRIVATE common_warnings)