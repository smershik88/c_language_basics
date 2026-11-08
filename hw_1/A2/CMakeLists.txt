add_executable(A2 main.c)

# Переопределяем требуемый стандарт языка
target_compile_features(A2 PRIVATE c_std_11)

# Подключаем предупреждения и, при необходимости, санитайзеры.
enable_common_checks(A2)