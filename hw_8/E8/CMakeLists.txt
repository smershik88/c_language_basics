add_executable(E8 main.c)
target_compile_features(E8 PRIVATE c_std_11)
target_link_libraries(E8 PRIVATE common_warnings)