add_executable(C18 main.c)

# Переопределяем требуемый стандарт языка
target_compile_features(C18 PRIVATE c_std_11)

# Подключаем предупреждения и, при необходимости, санитайзеры.
enable_common_checks(C18)