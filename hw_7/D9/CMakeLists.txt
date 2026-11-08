add_executable(D9 main.c)

# Переопределяем требуемый стандарт языка
target_compile_features(D9 PRIVATE c_std_11)

# Подключаем предупреждения и, при необходимости, санитайзеры.
enable_common_checks(D9)