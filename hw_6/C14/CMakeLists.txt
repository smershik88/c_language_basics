add_executable(C14 main.c)
target_compile_features(C14 PRIVATE c_std_11)
target_link_libraries(C14 PRIVATE common_warnings)
