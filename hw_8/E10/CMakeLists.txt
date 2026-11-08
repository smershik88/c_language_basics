add_executable(E10 main.c)

# Переопределяем требуемый стандарт языка
target_compile_features(E10 PRIVATE c_std_11)

# Подключаем предупреждения и, при необходимости, санитайзеры.
enable_common_checks(E10)