add_executable(G2 main.c)

# Переопределяем требуемый стандарт языка
target_compile_features(G2 PRIVATE c_std_11)

# Подключаем предупреждения и, при необходимости, санитайзеры.
enable_common_checks(G2)