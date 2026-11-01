add_executable(E19 main.c)
target_compile_features(E19 PRIVATE c_std_11)
target_link_libraries(E19 PRIVATE common_warnings)