add_executable(B4 main.c)

# Переопределяем требуемый стандарт языка
target_compile_features(B4 PRIVATE c_std_11)

# Подключаем предупреждения и, при необходимости, санитайзеры.
enable_common_checks(B4)