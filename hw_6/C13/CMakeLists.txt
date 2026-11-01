add_executable(C13 main.c)
target_compile_features(C13 PRIVATE c_std_11)
target_link_libraries(C13 PRIVATE common_warnings)
