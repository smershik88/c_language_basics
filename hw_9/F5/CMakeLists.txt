add_executable(F5 main.c)

# Переопределяем требуемый стандарт языка
target_compile_features(F5 PRIVATE c_std_11)

# Подключаем предупреждения и, при необходимости, санитайзеры.
enable_common_checks(F5)