add_executable(B8 main.c)

# Переопределяем требуемый стандарт языка
target_compile_features(B8 PRIVATE c_std_11)

# Подключаем предупреждения и, при необходимости, санитайзеры.
enable_common_checks(B8)