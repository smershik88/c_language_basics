add_executable(A12 main.c)

# Переопределяем требуемый стандарт языка
target_compile_features(A12 PRIVATE c_std_11)

# Подключаем предупреждения и, при необходимости, санитайзеры.
enable_common_checks(A12)