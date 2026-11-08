add_executable(D2 main.c)

# Переопределяем требуемый стандарт языка
target_compile_features(D2 PRIVATE c_std_11)

# Подключаем предупреждения и, при необходимости, санитайзеры.
enable_common_checks(D2)