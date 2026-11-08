add_executable(A14 main.c)

# Переопределяем требуемый стандарт языка
target_compile_features(A14 PRIVATE c_std_11)

# Подключаем предупреждения и, при необходимости, санитайзеры.
enable_common_checks(A14)