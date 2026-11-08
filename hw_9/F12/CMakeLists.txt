add_executable(F12 main.c)

# Переопределяем требуемый стандарт языка
target_compile_features(F12 PRIVATE c_std_11)

# Подключаем предупреждения и, при необходимости, санитайзеры.
enable_common_checks(F12)