add_executable(C2 main.c)
target_compile_features(C2 PRIVATE c_std_11)
target_link_libraries(C2 PRIVATE common_warnings)
