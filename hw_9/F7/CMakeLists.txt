add_executable(F7 main.c)

# Переопределяем требуемый стандарт языка
target_compile_features(F7 PRIVATE c_std_11)

# Подключаем предупреждения и, при необходимости, санитайзеры.
enable_common_checks(F7)