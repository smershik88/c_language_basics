add_executable(F6 main.c)

# Переопределяем требуемый стандарт языка
target_compile_features(F6 PRIVATE c_std_11)

# Подключаем предупреждения и, при необходимости, санитайзеры.
enable_common_checks(F6)