add_executable(F14 main.c)
target_compile_features(F14 PRIVATE c_std_11)
target_link_libraries(F14 PRIVATE common_warnings)