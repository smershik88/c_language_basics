add_executable(A11 main.c)

# Переопределяем требуемый стандарт языка
target_compile_features(A11 PRIVATE c_std_11)

# Подключаем предупреждения и, при необходимости, санитайзеры.
enable_common_checks(A11)