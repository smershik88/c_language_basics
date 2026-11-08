add_executable(A3 main.c)

# Переопределяем требуемый стандарт языка
target_compile_features(A3 PRIVATE c_std_11)

# Подключаем предупреждения и, при необходимости, санитайзеры.
enable_common_checks(A3)