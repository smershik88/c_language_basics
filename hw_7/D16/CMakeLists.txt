add_executable(D16 main.c)

# Переопределяем требуемый стандарт языка
target_compile_features(D16 PRIVATE c_std_11)

# Подключаем предупреждения и, при необходимости, санитайзеры.
enable_common_checks(D16)