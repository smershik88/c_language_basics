add_executable(D11 main.c)
target_compile_features(D11 PRIVATE c_std_11)
target_link_libraries(D11 PRIVATE common_warnings)