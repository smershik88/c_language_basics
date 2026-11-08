add_executable(C7 main.c)

# Переопределяем требуемый стандарт языка
target_compile_features(C7 PRIVATE c_std_11)

# Подключаем предупреждения и, при необходимости, санитайзеры.
enable_common_checks(C7)