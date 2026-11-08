add_executable(D10 main.c)

# Переопределяем требуемый стандарт языка
target_compile_features(D10 PRIVATE c_std_11)

# Подключаем предупреждения и, при необходимости, санитайзеры.
enable_common_checks(D10)