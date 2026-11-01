add_executable(C20 main.c)
target_compile_features(C20 PRIVATE c_std_11)
target_link_libraries(C20 PRIVATE common_warnings)
