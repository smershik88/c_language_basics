add_executable(E6 main.c)

# Переопределяем требуемый стандарт языка
target_compile_features(E6 PRIVATE c_std_11)

# Подключаем предупреждения и, при необходимости, санитайзеры.
enable_common_checks(E6)