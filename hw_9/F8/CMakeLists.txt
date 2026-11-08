add_executable(F8 main.c)

# Переопределяем требуемый стандарт языка
target_compile_features(F8 PRIVATE c_std_11)

# Подключаем предупреждения и, при необходимости, санитайзеры.
enable_common_checks(F8)