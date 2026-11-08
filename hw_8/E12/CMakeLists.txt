add_executable(E12 main.c)

# Переопределяем требуемый стандарт языка
target_compile_features(E12 PRIVATE c_std_11)

# Подключаем предупреждения и, при необходимости, санитайзеры.
enable_common_checks(E12)