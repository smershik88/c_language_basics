add_executable(E18 main.c)
target_compile_features(E18 PRIVATE c_std_11)
target_link_libraries(E18 PRIVATE common_warnings)