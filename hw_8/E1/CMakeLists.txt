add_executable(E1 main.c)
target_compile_features(E1 PRIVATE c_std_11)
target_link_libraries(E1 PRIVATE common_warnings)