add_executable(F4 main.c)

# Переопределяем требуемый стандарт языка
target_compile_features(F4 PRIVATE c_std_11)

# Подключаем предупреждения и, при необходимости, санитайзеры.
enable_common_checks(F4)