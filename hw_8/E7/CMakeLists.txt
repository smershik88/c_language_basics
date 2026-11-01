add_executable(E7 main.c)
target_compile_features(E7 PRIVATE c_std_11)
target_link_libraries(E7 PRIVATE common_warnings)