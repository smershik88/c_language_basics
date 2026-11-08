add_executable(B5 main.c)

# Переопределяем требуемый стандарт языка
target_compile_features(B5 PRIVATE c_std_11)

# Подключаем предупреждения и, при необходимости, санитайзеры.
enable_common_checks(B5)