cmake_minimum_required(VERSION 3.13)

project(c_language_basics VERSION 0.1.0 LANGUAGES C)


# ============================================================
# 1. Настройки стандарта C
# ============================================================

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)


# ============================================================
# 2. Базовый профиль предупреждений GCC и Clang
# ============================================================

add_library(common_warnings INTERFACE)

target_compile_options(common_warnings INTERFACE

    # --------------------------------------------------------
    # 2.1. Основные предупреждения
    # --------------------------------------------------------

    "$<$<OR:$<C_COMPILER_ID:GNU>,$<C_COMPILER_ID:Clang>>:-Wall>"
    # Включает широкий набор распространённых предупреждений:
    # неиспользуемый код и переменные, подозрительные конструкции,
    # некорректные форматы и другие потенциальные ошибки.
    # Не означает «все существующие предупреждения».

    "$<$<OR:$<C_COMPILER_ID:GNU>,$<C_COMPILER_ID:Clang>>:-Wextra>"
    # Включает дополнительные предупреждения, не входящие в -Wall.
    # Добавляет проверки некоторых сравнений, параметров функций,
    # инициализаторов и других конструкций.

    "$<$<OR:$<C_COMPILER_ID:GNU>,$<C_COMPILER_ID:Clang>>:-pedantic>"
    # Просит компилятор диагностировать использование расширений,
    # не предусмотренных выбранной версией стандарта ISO C.
    # Вместе с CMAKE_C_EXTENSIONS OFF помогает писать стандартный C.


    # --------------------------------------------------------
    # 2.2. Функции, объявления и прототипы
    # --------------------------------------------------------

    "$<$<OR:$<C_COMPILER_ID:GNU>,$<C_COMPILER_ID:Clang>>:-Wstrict-prototypes>"
    # Предупреждает об объявлениях функций без прототипа параметров.
    # В C int f() не означает «функция без параметров»;
    # для этого следует писать int f(void).

    "$<$<OR:$<C_COMPILER_ID:GNU>,$<C_COMPILER_ID:Clang>>:-Wmissing-prototypes>"
    # Предупреждает, если глобальная функция определена без
    # предварительного объявления её прототипа.

    "$<$<OR:$<C_COMPILER_ID:GNU>,$<C_COMPILER_ID:Clang>>:-Wcast-function-type>"
    # Предупреждает о подозрительном приведении указателя на функцию
    # к несовместимому типу функции. Особенно полезно для callback.

    "$<$<OR:$<C_COMPILER_ID:GNU>,$<C_COMPILER_ID:Clang>>:-Wbad-function-cast>"
    # Предупреждает о приведении результата вызова функции
    # к несовместимому или неожиданному типу.


    # --------------------------------------------------------
    # 2.3. Имена и области видимости
    # --------------------------------------------------------

    "$<$<OR:$<C_COMPILER_ID:GNU>,$<C_COMPILER_ID:Clang>>:-Wshadow>"
    # Предупреждает о затенении идентификаторов во вложенных
    # или пересекающихся областях видимости.


    # --------------------------------------------------------
    # 2.4. Преобразования типов и арифметика
    # --------------------------------------------------------

    "$<$<OR:$<C_COMPILER_ID:GNU>,$<C_COMPILER_ID:Clang>>:-Wconversion>"
    # Предупреждает о неявных преобразованиях, которые могут
    # изменить значение, знак или точность данных.

    "$<$<OR:$<C_COMPILER_ID:GNU>,$<C_COMPILER_ID:Clang>>:-Wsign-conversion>"
    # Выделяет преобразования между знаковыми и беззнаковыми
    # целочисленными типами, способные изменить интерпретацию значения.

    "$<$<OR:$<C_COMPILER_ID:GNU>,$<C_COMPILER_ID:Clang>>:-Wdouble-promotion>"
    # Предупреждает о неявном повышении float до double.
    # Помогает изучать integer/float promotions и арифметические
    # преобразования, в том числе продвижение float-аргументов.

    "$<$<OR:$<C_COMPILER_ID:GNU>,$<C_COMPILER_ID:Clang>>:-Wfloat-equal>"
    # Предупреждает о непосредственном сравнении float/double
    # операторами == и !=. Такое сравнение не всегда ошибочно,
    # но требует понимания точности представления чисел.

    "$<$<OR:$<C_COMPILER_ID:GNU>,$<C_COMPILER_ID:Clang>>:-Wenum-conversion>"
    # Предупреждает о неявных преобразованиях между разными
    # перечисляемыми типами enum.


    # --------------------------------------------------------
    # 2.5. Форматированный ввод и вывод
    # --------------------------------------------------------

    "$<$<OR:$<C_COMPILER_ID:GNU>,$<C_COMPILER_ID:Clang>>:-Wformat=2>"
    # Включает расширенные проверки printf/scanf и родственных функций:
    # соответствие спецификаторов типам аргументов, безопасность
    # форматной строки и некоторые подозрительные форматы.


    # --------------------------------------------------------
    # 2.6. Указатели, квалификаторы и выравнивание
    # --------------------------------------------------------

    "$<$<OR:$<C_COMPILER_ID:GNU>,$<C_COMPILER_ID:Clang>>:-Wpointer-arith>"
    # Предупреждает о нестандартной арифметике указателей,
    # например об арифметике над void* или указателями на функции.

    "$<$<OR:$<C_COMPILER_ID:GNU>,$<C_COMPILER_ID:Clang>>:-Wcast-qual>"
    # Предупреждает о приведении указателей, удаляющем const/volatile.
    # Само приведение не обязательно приводит к UB, но запись через
    # такой указатель в объект, объявленный const, недопустима.

    "$<$<OR:$<C_COMPILER_ID:GNU>,$<C_COMPILER_ID:Clang>>:-Wcast-align>"
    # Предупреждает о приведении указателя, которое может нарушить
    # требования выравнивания целевого типа.


    # --------------------------------------------------------
    # 2.7. Массивы, строки и работа с памятью
    # --------------------------------------------------------

    "$<$<OR:$<C_COMPILER_ID:GNU>,$<C_COMPILER_ID:Clang>>:-Warray-bounds>"
    # Обнаруживает некоторые обращения за границы массива,
    # если компилятор может установить это при анализе кода.

    "$<$<OR:$<C_COMPILER_ID:GNU>,$<C_COMPILER_ID:Clang>>:-Wsizeof-pointer-div>"
    # Предупреждает об ошибочной попытке вычислить количество
    # элементов через sizeof(ptr) / sizeof(ptr[0]), когда ptr — указатель.

    "$<$<OR:$<C_COMPILER_ID:GNU>,$<C_COMPILER_ID:Clang>>:-Wsizeof-pointer-memaccess>"
    # Обнаруживает подозрительное использование sizeof указателя
    # как размера буфера в memcpy, memset и родственных функциях.

    "$<$<OR:$<C_COMPILER_ID:GNU>,$<C_COMPILER_ID:Clang>>:-Wvla>"
    # Предупреждает об использовании массивов переменной длины (VLA).
    # VLA обязательны в C99 (с оговорёнными исключениями для типов
    # переменной модификации) и являются необязательной возможностью C11.

    "$<$<OR:$<C_COMPILER_ID:GNU>,$<C_COMPILER_ID:Clang>>:-Walloca>"
    # Предупреждает об использовании alloca для выделения памяти
    # в стеке. alloca не входит в стандарт ISO C.


    # --------------------------------------------------------
    # 2.8. Перечисления и управляющие конструкции
    # --------------------------------------------------------

    "$<$<OR:$<C_COMPILER_ID:GNU>,$<C_COMPILER_ID:Clang>>:-Wswitch-enum>"
    # Предупреждает, если в switch не обработаны отдельные значения
    # enum. Продолжает проверку даже при наличии ветки default.

    "$<$<OR:$<C_COMPILER_ID:GNU>,$<C_COMPILER_ID:Clang>>:-Wswitch-default>"
    # Предупреждает об отсутствии default в switch.
    # Это стилевое требование: default нужен не во всех switch.

    "$<$<OR:$<C_COMPILER_ID:GNU>,$<C_COMPILER_ID:Clang>>:-Wimplicit-fallthrough>"
    # Предупреждает о неявном переходе из одного case в следующий.
    # Если переход намеренный, его следует явно пометить способом,
    # поддерживаемым используемым компилятором.


    # --------------------------------------------------------
    # 2.9. Инициализация объектов
    # --------------------------------------------------------

    "$<$<OR:$<C_COMPILER_ID:GNU>,$<C_COMPILER_ID:Clang>>:-Wmissing-field-initializers>"
    # Предупреждает о пропущенных полях при инициализации структур
    # и объединений. В C пропущенные элементы агрегата обнуляются,
    # поэтому предупреждение не всегда означает ошибку.


    # --------------------------------------------------------
    # 2.10. Препроцессор
    # --------------------------------------------------------

    "$<$<OR:$<C_COMPILER_ID:GNU>,$<C_COMPILER_ID:Clang>>:-Wundef>"
    # Предупреждает об использовании неопределённых макросов
    # в выражениях #if. Помогает находить опечатки в именах макросов.


    # --------------------------------------------------------
    # 2.11. Выравнивание и расположение полей структур
    # --------------------------------------------------------

    "$<$<OR:$<C_COMPILER_ID:GNU>,$<C_COMPILER_ID:Clang>>:-Wpadded>"
    # Предупреждает о padding между полями структуры или в её конце.
    # Полезен для изучения sizeof, offsetof, выравнивания и ABI.
    # Может создавать много предупреждений.

    "$<$<OR:$<C_COMPILER_ID:GNU>,$<C_COMPILER_ID:Clang>>:-Wpacked>"
    # Предупреждает о некоторых бесполезных или избыточных применениях
    # атрибута packed. Сам атрибут packed не является стандартом ISO C.


    # ========================================================
    # 2.12. Дополнительные флаги только для GCC
    # ========================================================

    "$<$<C_COMPILER_ID:GNU>:-Woverflow>"
    # Предупреждает о переполнениях, которые можно определить
    # непосредственно во время компиляции, например в константах.

    "$<$<C_COMPILER_ID:GNU>:-Wwrite-strings>"
    # В режиме C трактует строковые литералы как const char[]
    # для целей проверки типов и обнаружения попыток их изменения.
    # Это поведение диагностики GCC, а не изменение типа литерала
    # в стандарте C: тип строкового литерала в C — массив char.

    "$<$<C_COMPILER_ID:GNU>:-Wold-style-definition>"
    # Предупреждает об устаревшем стиле определения функций K&R.

    "$<$<C_COMPILER_ID:GNU>:-Wnull-dereference>"
    # Предупреждает о возможном разыменовании NULL, если компилятор
    # может установить такую ситуацию при анализе программы.

    "$<$<C_COMPILER_ID:GNU>:-Wduplicated-cond>"
    # Обнаруживает повторяющиеся условия в цепочке if / else if.

    "$<$<C_COMPILER_ID:GNU>:-Wduplicated-branches>"
    # Обнаруживает одинаковое содержимое ветвей if и else.

    "$<$<C_COMPILER_ID:GNU>:-Wlogical-op>"
    # Обнаруживает некоторые подозрительные применения && и ||,
    # например возможную путаницу с побитовыми & и |.

    "$<$<C_COMPILER_ID:GNU>:-Wjump-misses-init>"
    # Предупреждает о переходах goto или switch, перескакивающих
    # через инициализацию переменных. GNU-специфичная диагностика.

    "$<$<C_COMPILER_ID:GNU>:-Wstrict-overflow=2>"
    # Предупреждает о некоторых оптимизациях, опирающихся на правило,
    # что переполнение знакового целого не происходит.
    # Не является полноценным детектором переполнений; зависит от -O.

    "$<$<C_COMPILER_ID:GNU>:-Wstrict-aliasing=2>"
    # Пытается обнаруживать некоторые нарушения strict aliasing.
    # Проверка неполная и зависит от оптимизации и анализа компилятора.

    "$<$<C_COMPILER_ID:GNU>:-Wnested-externs>"
    # Предупреждает об объявлении extern внутри функции.
    # В C это допустимо, но обычно интерфейсы размещают в заголовках.

    "$<$<C_COMPILER_ID:GNU>:-Wredundant-decls>"
    # Обнаруживает повторные объявления идентификаторов.
    # Повторные совместимые объявления в C разрешены, но иногда
    # указывают на лишние объявления или проблемы организации API.

    "$<$<C_COMPILER_ID:GNU>:-Wdangling-pointer=2>"
    # Обнаруживает использование указателей на объекты с автоматическим
    # временем хранения после завершения времени жизни этих объектов.
    # Уровень 2 также проверяет некоторые условные пути выполнения.

    "$<$<C_COMPILER_ID:GNU>:-Wuse-after-free=3>"
    # Обнаруживает использование указателей после освобождения памяти
    # через free/realloc. Уровень 3 дополнительно проверяет некоторые
    # сравнения таких указателей; это наиболее строгий уровень.

    "$<$<C_COMPILER_ID:GNU>:-Wcast-align=strict>"
    # Более строгая проверка приведения указателей с потенциальным
    # нарушением выравнивания, чем общий -Wcast-align.

    "$<$<C_COMPILER_ID:GNU>:-Wshift-overflow=2>"
    # Расширенная диагностика переполнений при сдвиге влево,
    # в том числе некоторых случаев со знаковыми значениями.

    "$<$<C_COMPILER_ID:GNU>:-Wformat-overflow=2>"
    # Ищет потенциальное переполнение буфера при форматированном
    # выводе, например через sprintf. Уровень 2 строже уровня 1.

    "$<$<C_COMPILER_ID:GNU>:-Wformat-truncation=2>"
    # Ищет потенциальное усечение результата форматированного вывода,
    # например в snprintf. Усечение не обязательно означает выход
    # за границы памяти, но может приводить к потере данных.

    "$<$<C_COMPILER_ID:GNU>:-Wstringop-truncation>"
    # Обнаруживает подозрительное усечение строк при использовании
    # strncpy, strncat и некоторых родственных функций.

    "$<$<C_COMPILER_ID:GNU>:-Wsizeof-array-argument>"
    # Предупреждает, если sizeof применяется к параметру функции,
    # объявленному как массив: в параметрах функции он корректируется
    # до указателя, поэтому sizeof возвращает размер указателя.

    "$<$<C_COMPILER_ID:GNU>:-Walloc-zero>"
    # Предупреждает о вызовах функций выделения памяти с нулевым
    # размером. Поведение таких вызовов имеет специальные правила
    # стандарта и зависит от конкретной функции и реализации.

    "$<$<C_COMPILER_ID:GNU>:-Wtrampolines>"
    # Предупреждает о генерации trampolines при использовании
    # вложенных функций — расширения GCC, отсутствующего в ISO C.

    "$<$<C_COMPILER_ID:GNU>:-Wunsuffixed-float-constants>"
    # Предупреждает о вещественных константах без суффикса f или l.
    # Например, 1.0 имеет тип double, а 1.0f — тип float.


    # ========================================================
    # 2.13. Дополнительные флаги только для Clang
    # ========================================================

    "$<$<C_COMPILER_ID:Clang>:-Wconditional-uninitialized>"
    # Обнаруживает использование переменных, которые могут остаться
    # неинициализированными на некоторых путях выполнения.

    "$<$<C_COMPILER_ID:Clang>:-Wcomma>"
    # Предупреждает о подозрительном или неожиданном использовании
    # оператора запятая.

    "$<$<C_COMPILER_ID:Clang>:-Wconstant-conversion>"
    # Обнаруживает некоторые преобразования констант, при которых
    # значение может измениться или потерять точность.

    "$<$<C_COMPILER_ID:Clang>:-Wimplicit-int-conversion>"
    # Детализирует диагностику неявных целочисленных преобразований,
    # включая сужение типа и потерю значащих битов.

    "$<$<C_COMPILER_ID:Clang>:-Wimplicit-float-conversion>"
    # Детализирует диагностику неявных преобразований float/double,
    # способных привести к потере точности или диапазона.

    "$<$<C_COMPILER_ID:Clang>:-Wunreachable-code>"
    # Обнаруживает некоторые участки кода, которые не могут выполниться.
    # Результат зависит от возможностей анализа компилятора.

    "$<$<C_COMPILER_ID:Clang>:-Wembedded-directive>"
    # Предупреждает о директивах препроцессора, размещённых внутри
    # аргументов вызова макроса.

    "$<$<C_COMPILER_ID:Clang>:-Wnewline-eof>"
    # Предупреждает об отсутствии символа новой строки в конце файла.
)


# ============================================================
# 3. Дополнительные статические и компиляторные проверки
# ============================================================

include(CheckCCompilerFlag)

# ------------------------------------------------------------
# 3.1. Статический анализатор GCC
# ------------------------------------------------------------

option(ENABLE_GCC_ANALYZER
    "Enable GCC static analyzer"
    ON
)

if(ENABLE_GCC_ANALYZER)
    if(CMAKE_C_COMPILER_ID STREQUAL "GNU")
        check_c_compiler_flag("-fanalyzer" HAS_GCC_ANALYZER)

        if(HAS_GCC_ANALYZER)
            target_compile_options(common_warnings INTERFACE
                "$<$<C_COMPILER_ID:GNU>:-fanalyzer>"
            )
        else()
            message(WARNING
                "ENABLE_GCC_ANALYZER is ON, but this GCC compiler does not support -fanalyzer."
            )
        endif()
    else()
        message(STATUS
            "ENABLE_GCC_ANALYZER is ON, but -fanalyzer is available only with GCC; skipped."
        )
    endif()
endif()


# ------------------------------------------------------------
# 3.2. Проверка небезопасной работы с буферами Clang
# ------------------------------------------------------------

option(ENABLE_CLANG_UNSAFE_BUFFER
    "Enable Clang unsafe buffer diagnostics"
    OFF
)

if(ENABLE_CLANG_UNSAFE_BUFFER)
    if(CMAKE_C_COMPILER_ID STREQUAL "Clang")
        # Clang может сообщать о неизвестном -W-флаге предупреждением.
        # Повышаем именно такую диагностику до ошибки, чтобы проверка
        # check_c_compiler_flag не приняла неподдерживаемый флаг.
        set(_SAVED_CMAKE_REQUIRED_FLAGS "${CMAKE_REQUIRED_FLAGS}")
        string(APPEND CMAKE_REQUIRED_FLAGS " -Werror=unknown-warning-option")

        check_c_compiler_flag(
            "-Wunsafe-buffer-usage"
            HAS_CLANG_UNSAFE_BUFFER_USAGE
        )

        set(CMAKE_REQUIRED_FLAGS "${_SAVED_CMAKE_REQUIRED_FLAGS}")
        unset(_SAVED_CMAKE_REQUIRED_FLAGS)

        if(HAS_CLANG_UNSAFE_BUFFER_USAGE)
            target_compile_options(common_warnings INTERFACE
                "$<$<C_COMPILER_ID:Clang>:-Wunsafe-buffer-usage>"
            )
        else()
            message(WARNING
                "ENABLE_CLANG_UNSAFE_BUFFER is ON, but this Clang compiler does not support -Wunsafe-buffer-usage."
            )
        endif()
    else()
        message(STATUS
            "ENABLE_CLANG_UNSAFE_BUFFER is ON, but the selected compiler is not Clang; skipped."
        )
    endif()
endif()


# ------------------------------------------------------------
# 3.3. Агрессивная проверка строковых операций GCC
# ------------------------------------------------------------

option(ENABLE_AGGRESSIVE_GCC_WARNINGS
    "Enable aggressive GCC diagnostics"
    OFF
)

if(ENABLE_AGGRESSIVE_GCC_WARNINGS)
    if(CMAKE_C_COMPILER_ID STREQUAL "GNU")
        check_c_compiler_flag("-Wstringop-overflow=4" HAS_GCC_STRINGOP_OVERFLOW_4)

        check_c_compiler_flag("-Warray-bounds=2" HAS_GCC_ARRAY_BOUNDS_2)

        if(HAS_GCC_STRINGOP_OVERFLOW_4)
            target_compile_options(common_warnings INTERFACE
                "$<$<C_COMPILER_ID:GNU>:-Wstringop-overflow=4>"
            )
        else()
            message(WARNING
                "ENABLE_AGGRESSIVE_GCC_WARNINGS is ON, but this GCC compiler does not support -Wstringop-overflow=4."
            )
        endif()

        if(HAS_GCC_ARRAY_BOUNDS_2)
            target_compile_options(common_warnings INTERFACE
                "$<$<C_COMPILER_ID:GNU>:-Warray-bounds=2>"
            )
        else()
            message(WARNING
                "ENABLE_AGGRESSIVE_GCC_WARNINGS is ON, but this GCC compiler does not support -Warray-bounds=2."
            )
        endif()
    else()
        message(STATUS
            "ENABLE_AGGRESSIVE_GCC_WARNINGS is ON, but the selected compiler is not GCC; skipped."
        )
    endif()
endif()


# ============================================================
# 4. Дополнительные правила и режимы строгости
# ============================================================

# ------------------------------------------------------------
# 4.1. Превращение выбранных предупреждений в ошибки
# ------------------------------------------------------------

option(ENABLE_STRICT_ERRORS
    "Treat selected diagnostics as errors"
    OFF
)

if(ENABLE_STRICT_ERRORS)
    target_compile_options(common_warnings INTERFACE

        "$<$<OR:$<C_COMPILER_ID:GNU>,$<C_COMPILER_ID:Clang>>:-Werror=implicit-function-declaration>"
        # Ошибка при вызове функции без предварительного объявления.
        # В C99 и более новых стандартах неявные объявления функций
        # не поддерживаются и нарушают ограничения языка.

        "$<$<OR:$<C_COMPILER_ID:GNU>,$<C_COMPILER_ID:Clang>>:-Werror=implicit-int>"
        # Ошибка при объявлении функции или объекта без явного типа.
        # Например, старый стиль foo() { ... }.

        "$<$<OR:$<C_COMPILER_ID:GNU>,$<C_COMPILER_ID:Clang>>:-Werror=int-conversion>"
        # Превращает предупреждения о несовместимых преобразованиях
        # целочисленных и указательных типов в ошибки.

        "$<$<OR:$<C_COMPILER_ID:GNU>,$<C_COMPILER_ID:Clang>>:-Werror=incompatible-pointer-types>"
        # Превращает присваивание, передачу или возврат указателей
        # несовместимых типов в ошибку.

        "$<$<OR:$<C_COMPILER_ID:GNU>,$<C_COMPILER_ID:Clang>>:-Werror=return-type>"
        # Превращает диагностику некорректного типа возврата
        # или отсутствующего обязательного return в ошибку.

        "$<$<OR:$<C_COMPILER_ID:GNU>,$<C_COMPILER_ID:Clang>>:-Werror=strict-prototypes>"
        # Превращает предупреждения о функциях без строгого прототипа
        # в ошибки.
    )
endif()


# ------------------------------------------------------------
# 4.2. Запрет массивов переменной длины (VLA)
# ------------------------------------------------------------

option(DISABLE_VLA
    "Disallow variable length arrays"
    OFF
)

if(DISABLE_VLA)
    target_compile_options(common_warnings INTERFACE
        "$<$<OR:$<C_COMPILER_ID:GNU>,$<C_COMPILER_ID:Clang>>:-Werror=vla>"
    )
endif()


# ------------------------------------------------------------
# 4.3. Проверки совместимости со старыми стандартами C
# ------------------------------------------------------------

option(ENABLE_C_COMPAT_WARNINGS
    "Enable C standard compatibility diagnostics"
    OFF
)

if(ENABLE_C_COMPAT_WARNINGS)
    target_compile_options(common_warnings INTERFACE

        "$<$<OR:$<C_COMPILER_ID:GNU>,$<C_COMPILER_ID:Clang>>:-Wdeclaration-after-statement>"
        # Предупреждает об объявлениях после исполняемых операторов.
        # Полезно для стиля C90, где объявления в блоке размещались
        # до исполняемых операторов. Само по себе не переключает стандарт.

        "$<$<C_COMPILER_ID:GNU>:-Wc90-c99-compat>"
        # GCC: предупреждает об использовании возможностей C99,
        # отсутствующих в C90.

        "$<$<C_COMPILER_ID:GNU>:-Wc99-c11-compat>"
        # GCC: предупреждает об использовании возможностей C11,
        # отсутствующих в C99.
    )
endif()


# ============================================================
# 5. Санитайзеры времени выполнения
# ============================================================

option(ENABLE_SANITIZERS
    "Enable AddressSanitizer and UndefinedBehaviorSanitizer"
    OFF
)

add_library(common_sanitizers INTERFACE)

if(ENABLE_SANITIZERS)
    # Проверяем доступность полного набора для выбранного компилятора.
    # Проверка выполняется при конфигурации и включает компиляцию/линковку
    # тестовой программы. Наличие флага не гарантирует поддержку на
    # любой целевой платформе, поэтому результат зависит от toolchain.
    if(CMAKE_C_COMPILER_ID STREQUAL "GNU")
        # check_c_compiler_flag передаёт проверяемый флаг компилятору,
        # но для тестовой линковки runtime также должен быть добавлен
        # в CMAKE_EXE_LINKER_FLAGS.
        set(_SAVED_CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS}")
        string(APPEND CMAKE_EXE_LINKER_FLAGS " -fsanitize=address,undefined")

        check_c_compiler_flag(
            "-fsanitize=address,undefined"
            HAS_GCC_ADDRESS_UNDEFINED_SANITIZERS
        )

        set(CMAKE_EXE_LINKER_FLAGS "${_SAVED_CMAKE_EXE_LINKER_FLAGS}")
        unset(_SAVED_CMAKE_EXE_LINKER_FLAGS)

        if(NOT HAS_GCC_ADDRESS_UNDEFINED_SANITIZERS)
            message(FATAL_ERROR
                "ENABLE_SANITIZERS is ON, but GCC cannot compile and link with -fsanitize=address,undefined."
            )
        endif()

    elseif(CMAKE_C_COMPILER_ID STREQUAL "Clang")
        set(_SAVED_CMAKE_REQUIRED_FLAGS "${CMAKE_REQUIRED_FLAGS}")
        set(_SAVED_CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS}")
        string(APPEND CMAKE_REQUIRED_FLAGS
            " -Werror=unknown-warning-option -Werror=unknown-sanitizers"
        )
        string(APPEND CMAKE_EXE_LINKER_FLAGS
            " -fsanitize=address,undefined,integer"
        )

        check_c_compiler_flag(
            "-fsanitize=address,undefined,integer"
            HAS_CLANG_ADDRESS_UNDEFINED_INTEGER_SANITIZERS
        )

        set(CMAKE_REQUIRED_FLAGS "${_SAVED_CMAKE_REQUIRED_FLAGS}")
        set(CMAKE_EXE_LINKER_FLAGS "${_SAVED_CMAKE_EXE_LINKER_FLAGS}")
        unset(_SAVED_CMAKE_REQUIRED_FLAGS)
        unset(_SAVED_CMAKE_EXE_LINKER_FLAGS)

        if(NOT HAS_CLANG_ADDRESS_UNDEFINED_INTEGER_SANITIZERS)
            message(FATAL_ERROR
                "ENABLE_SANITIZERS is ON, but Clang cannot compile and link with -fsanitize=address,undefined,integer."
            )
        endif()

    else()
        message(FATAL_ERROR
            "ENABLE_SANITIZERS supports only GCC and Clang in this configuration."
        )
    endif()
endif()

# Флаги инструментирования исходного кода.
target_compile_options(common_sanitizers INTERFACE

    "$<$<C_COMPILER_ID:GNU>:-fsanitize=address,undefined>"
    # GCC: AddressSanitizer + UndefinedBehaviorSanitizer.

    "$<$<C_COMPILER_ID:Clang>:-fsanitize=address,undefined,integer>"
    # Clang: AddressSanitizer + UndefinedBehaviorSanitizer
    # + Integer Sanitizer. Последний дополнительно проверяет, например,
    # беззнаковое переполнение и некоторые неявные потери данных.

    "$<$<OR:$<C_COMPILER_ID:GNU>,$<C_COMPILER_ID:Clang>>:-fno-omit-frame-pointer>"
    # Сохраняет frame pointer и обычно улучшает стек вызовов
    # в диагностических сообщениях санитайзеров.
)

# Флаги линковки: runtime санитайзеров должен быть подключён
# к конечному исполняемому файлу.
target_link_options(common_sanitizers INTERFACE

    "$<$<C_COMPILER_ID:GNU>:-fsanitize=address,undefined>"
    # GCC: подключает runtime AddressSanitizer и UBSan.

    "$<$<C_COMPILER_ID:Clang>:-fsanitize=address,undefined,integer>"
    # Clang: подключает runtime AddressSanitizer, UBSan и Integer Sanitizer.
)


# ============================================================
# 6. Функция подключения проверок к целям
# ============================================================

function(enable_common_checks target_name)
    if(NOT TARGET "${target_name}")
        message(FATAL_ERROR
            "enable_common_checks(): target '${target_name}' does not exist. "
            "Call this function after add_executable() or add_library()."
        )
    endif()

    # Подключает общие предупреждения и условно включённые диагностики.
    target_link_libraries("${target_name}" PRIVATE common_warnings)

    # Санитайзеры подключаются только при ENABLE_SANITIZERS=ON.
    if(ENABLE_SANITIZERS)
        target_link_libraries("${target_name}" PRIVATE common_sanitizers)
    endif()
endfunction()


# ============================================================
# 7. Учебные проекты
# ============================================================

add_subdirectory(hw_1 hw_1)
add_subdirectory(hw_2 hw_2)
add_subdirectory(hw_3 hw_3)
add_subdirectory(hw_4 hw_4)
add_subdirectory(hw_5 hw_5)
add_subdirectory(hw_6 hw_6)
add_subdirectory(hw_7 hw_7)
add_subdirectory(hw_8 hw_8)
add_subdirectory(hw_9 hw_9)
