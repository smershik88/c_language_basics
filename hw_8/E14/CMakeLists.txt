add_executable(E14 main.c)

# Переопределяем требуемый стандарт языка
target_compile_features(E14 PRIVATE c_std_11)

# Подключаем предупреждения и, при необходимости, санитайзеры.
enable_common_checks(E14)