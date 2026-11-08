add_executable(A7 main.c)

# Переопределяем требуемый стандарт языка
target_compile_features(A7 PRIVATE c_std_11)

# Подключаем предупреждения и, при необходимости, санитайзеры.
enable_common_checks(A7)