add_executable(D14 main.c)
target_compile_features(D14 PRIVATE c_std_11)
target_link_libraries(D14 PRIVATE common_warnings)