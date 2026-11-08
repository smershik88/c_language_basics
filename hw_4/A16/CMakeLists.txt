add_executable(A16 main.c)

# Переопределяем требуемый стандарт языка
target_compile_features(A16 PRIVATE c_std_11)

# Подключаем предупреждения и, при необходимости, санитайзеры.
enable_common_checks(A16)