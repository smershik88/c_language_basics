add_executable(E20 main.c)

# Переопределяем требуемый стандарт языка
target_compile_features(E20 PRIVATE c_std_11)

# Подключаем предупреждения и, при необходимости, санитайзеры.
enable_common_checks(E20)