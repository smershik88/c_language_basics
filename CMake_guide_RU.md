# Руководство по корневому CMakeLists.txt

## 1. Назначение конфигурации

Корневой `CMakeLists.txt` задаёт единые правила для учебных проектов на C:

- выбирает стандарт C11 и отключает GNU-расширения;
- подключает общие предупреждения GCC и Clang;
- добавляет предупреждения, специфичные для GCC или Clang;
- по CMake-опциям включает дополнительные анализаторы и более строгие правила;
- при необходимости инструментирует код санитайзерами;
- предоставляет функцию `enable_common_checks()` для подключения предупреждений и санитайзеров к отдельным целям;
- при включении `clang-tidy` запускает статический анализ во время сборки;
- создаёт отдельные цели `format` и `format-check` для форматирования и проверки стиля кода.

В конфигурации используются разные механизмы:

| Механизм | Назначение |
|---|---|
| `common_warnings` (`INTERFACE`) | Передача предупреждений компилятора и дополнительных диагностик подключённым целям |
| `common_sanitizers` (`INTERFACE`) | Передача флагов инструментирования и линковки санитайзеров |
| `CMAKE_C_CLANG_TIDY` | Включение clang-tidy для C-целей, создаваемых после установки переменной |
| Цели `format` и `format-check` | Ручное форматирование и проверка форматирования файлов проекта |

Важно: `clang-tidy` и `clang-format` не являются флагами GCC/Clang. Это самостоятельные программы LLVM. `clang-tidy` анализирует исходный код через Clang Frontend, а `clang-format` форматирует исходные файлы.

## 2. Стандарт языка C

В корневом файле установлено:

```cmake
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)
```

Значение параметров:

- `CMAKE_C_STANDARD 11` — использовать стандарт C11;
- `CMAKE_C_STANDARD_REQUIRED ON` — не разрешать CMake молча выбрать более старый стандарт;
- `CMAKE_C_EXTENSIONS OFF` — использовать стандартный режим (`-std=c11`), а не режим с расширениями компилятора (`-std=gnu11`).

Чтобы перейти на C99, измени `11` на `99`. Для разных стандартов или компиляторов используй отдельные каталоги сборки: один каталог CMake не следует повторно использовать с другим компилятором.

## 3. Как подключать проверки к учебным заданиям

В каждом подкаталоге сначала создаётся цель, затем к ней вызывается `enable_common_checks()`.

Пример `hw_1/CMakeLists.txt`:

```cmake
add_executable(hw_1
    main.c
    helpers.c
)

enable_common_checks(hw_1)
```

Для нескольких исполняемых файлов функцию вызывают для каждого:

```cmake
add_executable(hw_1 main.c)
enable_common_checks(hw_1)

add_executable(hw_1_tests tests.c)
enable_common_checks(hw_1_tests)
```

Если в задании есть собственная библиотека, к ней также можно подключить проверки:

```cmake
add_library(hw_1_lib STATIC helpers.c)
enable_common_checks(hw_1_lib)

add_executable(hw_1 main.c)
target_link_libraries(hw_1 PRIVATE hw_1_lib)
enable_common_checks(hw_1)
```

Для санитайзеров важно инструментировать именно те исходники, в которых нужно искать ошибки. Поэтому вызывай `enable_common_checks()` и для собственной библиотеки, и для конечного исполняемого файла, который её использует: библиотека получает флаги компиляции, а исполняемый файл — в том числе параметры линковки runtime санитайзера.

Если `enable_common_checks()` не вызвать для цели, к ней не применятся `common_warnings` и `common_sanitizers`.

**Отдельный случай — clang-tidy.** В корневом файле `CMAKE_C_CLANG_TIDY` устанавливается до вызовов `add_subdirectory()`. CMake использует эту переменную для инициализации свойства `C_CLANG_TIDY` у создаваемых после этого C-целей. Поэтому clang-tidy не зависит от вызова `enable_common_checks()`. Саму функцию всё равно нужно вызывать для подключения предупреждений и санитайзеров.

## 4. CMake-опции и переменные, управляющие проверками

Параметры, созданные через `option()`, — это **CMake cache options**, а не макросы препроцессора C и не `#define`. Их задают при конфигурации через `-DИМЯ=ON` или `-DИМЯ=OFF`, либо в `cacheVariables` файла `CMakePresets.json`.

### 4.1. Сводная таблица опций

| Опция | По умолчанию | Назначение |
|---|---:|---|
| `ENABLE_GCC_ANALYZER` | `ON` | Для GCC добавляет `-fanalyzer`, если проверка поддержки успешна. Для других компиляторов пропускается. |
| `ENABLE_CLANG_UNSAFE_BUFFER` | `OFF` | Для Clang добавляет `-Wunsafe-buffer-usage`, если компилятор поддерживает флаг. Может выдавать много диагностик даже для намеренно низкоуровневого корректного кода. |
| `ENABLE_AGGRESSIVE_GCC_WARNINGS` | `OFF` | Для GCC включает `-Wstringop-overflow=4` и `-Warray-bounds=2`, если соответствующие проверки успешны. Возможны дополнительные предупреждения и ложные срабатывания. |
| `ENABLE_STRICT_ERRORS` | `OFF` | Превращает выбранные диагностики компилятора в ошибки. Это не глобальный `-Werror`. |
| `DISABLE_VLA` | `OFF` | Добавляет `-Werror=vla`: использование VLA становится ошибкой компиляции. |
| `ENABLE_C_COMPAT_WARNINGS` | `OFF` | Включает проверки стиля C90 и использования возможностей более новых стандартов. Стандарт проекта при этом не меняется. |
| `ENABLE_SANITIZERS` | `OFF` | Для GCC включает ASan + UBSan, для Clang — ASan + UBSan + Integer Sanitizer. Перед подключением проверяет компиляцию и линковку пробной программы. |
| `ENABLE_CLANG_TIDY` | `OFF` | Включает запуск clang-tidy во время сборки C-целей. Может использоваться и с GCC, и с Clang. |
| `ENABLE_CLANG_TIDY_WARNINGS_AS_ERRORS` | `OFF` | Передаёт clang-tidy `--warnings-as-errors=*`, превращая все его предупреждения в ошибки. Имеет смысл только при `ENABLE_CLANG_TIDY=ON`. |
| `ENABLE_CLANG_FORMAT_TARGETS` | `ON` | Создаёт цели `format` и `format-check`, если найден clang-format. |

### 4.2. Переменные с путями к программам

Это не опции включения/выключения, а переменные CMake cache, содержащие пути к исполняемым файлам:

| Переменная | Назначение |
|---|---|
| `CLANG_TIDY_EXECUTABLE` | Путь к `clang-tidy.exe`. При отсутствии заданного значения путь ищется через `find_program()`. |
| `CLANG_FORMAT_EXECUTABLE` | Путь к `clang-format.exe`. При отсутствии заданного значения путь ищется через `find_program()`. |

Обе переменные можно переопределить вручную через `-D` или `cacheVariables`, но это необязательно. В текущем `CMakeLists.txt` `find_program()` не содержит `HINTS`: сначала используй `PATH` процесса CMake. В MSYS2 удобнее добавить только `C:/msys64/ucrt64/bin` в `environment.PATH` нужного Configure Preset. Тогда поиск остаётся переносимым, а глобальный `PATH` Windows менять не требуется.

### 4.3. Статический анализатор GCC

`ENABLE_GCC_ANALYZER=ON` включён по умолчанию. GCC `-fanalyzer` анализирует возможные пути исполнения и способен находить некоторые ошибки управления ресурсами, времени жизни памяти, разыменования указателей и работы с файлами.

Это статический анализ: запускать программу для самого анализа не требуется. Анализатор не доказывает отсутствие ошибок и может увеличить время компиляции. Для Clang флаг GCC не подключается.

Отключение:

```bash
-DENABLE_GCC_ANALYZER=OFF
```

### 4.4. Небезопасная работа с буферами в Clang

`ENABLE_CLANG_UNSAFE_BUFFER=ON` добавляет `-Wunsafe-buffer-usage`. Флаг помогает находить участки кода с указателями, индексированием и доступом к буферам, которые требуют внимательной проверки границ.

Это диагностический профиль, а не доказательство наличия выхода за границы. Он может подсвечивать обычные операции с указателями, особенно в учебных примерах. Поддержка флага предварительно проверяется; при неизвестном параметре диагностика Clang `-Wunknown-warning-option` повышается до ошибки только на время пробной проверки.

Включение:

```bash
-DENABLE_CLANG_UNSAFE_BUFFER=ON
```

При использовании GCC опция не добавляет Clang-флаг и выводит информационное сообщение.

### 4.5. Строгий режим ошибок компилятора

`ENABLE_STRICT_ERRORS=ON` превращает в ошибки только выбранные диагностики: неявное объявление функций, `implicit int`, несовместимые указатели и преобразования, ошибки типа возврата и отсутствие строгих прототипов.

В отличие от глобального `-Werror`, этот режим не превращает каждое предупреждение в ошибку. Менее критичные предупреждения продолжают выводиться как предупреждения.

```bash
-DENABLE_STRICT_ERRORS=ON
```

### 4.6. Запрет VLA

`DISABLE_VLA=ON` превращает предупреждение `-Wvla` в ошибку компиляции. Это проектное ограничение, а не требование C11: VLA являются необязательной возможностью C11 и стандартной возможностью C99.

```bash
-DDISABLE_VLA=ON
```

### 4.7. Совместимость со старыми редакциями стандарта

`ENABLE_C_COMPAT_WARNINGS=ON` включает `-Wdeclaration-after-statement` для GCC/Clang, а также GCC-проверки `-Wc90-c99-compat` и `-Wc99-c11-compat`.

При этом `CMAKE_C_STANDARD` остаётся равным 11. Эти предупреждения не переключают стандарт компиляции. Если требуется действительно собрать проект в режиме C90 или C99, измени `CMAKE_C_STANDARD` и используй отдельный каталог сборки.

```bash
-DENABLE_C_COMPAT_WARNINGS=ON
```

### 4.8. Агрессивные проверки GCC

`ENABLE_AGGRESSIVE_GCC_WARNINGS=ON` добавляет:

- `-Wstringop-overflow=4` — строгую диагностику потенциального переполнения объектов при строковых и memory-операциях;
- `-Warray-bounds=2` — расширенную диагностику обращений за границы массивов, включая некоторые случаи, связанные с промежуточными результатами арифметики указателей.

Каждый флаг проверяется отдельно. Если конкретная версия GCC не поддерживает его, CMake выводит предупреждение и не добавляет соответствующий флаг.

```bash
-DENABLE_AGGRESSIVE_GCC_WARNINGS=ON
```

### 4.9. Санитайзеры времени выполнения

`ENABLE_SANITIZERS=ON` инструментирует исходный код и подключает runtime санитайзеров при линковке.

- **AddressSanitizer (ASan)** обнаруживает многие ошибки доступа к памяти: выходы за границы, use-after-free, double-free и некоторые другие ошибки.
- **UndefinedBehaviorSanitizer (UBSan)** обнаруживает выбранные виды неопределённого поведения, например некоторые недопустимые сдвиги, нарушения выравнивания, разыменование нулевых указателей и знаковое переполнение.
- **Integer Sanitizer в Clang** дополнительно обнаруживает некоторые подозрительные целочисленные операции, включая беззнаковое переполнение и потери данных при преобразованиях. Беззнаковое переполнение само по себе определено стандартом C, но может свидетельствовать о логической ошибке.

Санитайзеры обнаруживают ошибки только на тех путях кода, которые реально выполняются. После сборки нужно запускать программу и тестовые сценарии. Это инструменты разработки и тестирования, а не обычной Release-сборки.

При включении CMake проверяет, что выбранный компилятор способен скомпилировать и слинковать тестовую программу с соответствующим набором. Если проверка завершается неудачно, конфигурация прекращается с ошибкой.

**Особенность текущего окружения MSYS2 UCRT64:** в твоём предыдущем логе GCC `x86_64-w64-mingw32` не прошёл проверку `-fsanitize=address,undefined`. Для этого пресета оставляй `ENABLE_SANITIZERS=OFF`. Включать санитайзеры следует в отдельном пресете с компилятором и runtime, которые действительно проходят проверку CMake. Например, можно проверить Clang из MSYS2 CLANG64; успешную поддержку нужно подтвердить результатом configure-теста, а не предполагать заранее.

Пример включения там, где проверка проходит:

```bash
-DENABLE_SANITIZERS=ON
```

Для диагностической сборки полезны `Debug`, отладочная информация и `-fno-omit-frame-pointer` (последний уже добавляется интерфейсной целью санитайзеров).

### 4.10. Статический анализ clang-tidy

`ENABLE_CLANG_TIDY=ON` включает запуск clang-tidy во время сборки. Важно: **clang-tidy можно использовать и при компиляции проекта GCC**. GCC продолжает компилировать программу, а clang-tidy отдельно разбирает исходный код своим Clang Frontend.

Текущий CMake-файл:

1. ищет `clang-tidy` через `find_program()`;
2. передаёт ему корневой файл `.clang-tidy` через `--config-file`;
3. добавляет `--extra-arg=-Wno-unknown-warning-option`, чтобы Clang не выдавал предупреждения о неизвестных ему GCC-предупреждениях;
4. устанавливает `CMAKE_C_CLANG_TIDY` до `add_subdirectory()`, чтобы CMake инициализировал свойство `C_CLANG_TIDY` у создаваемых далее C-целей.

Для автоматического запуска через CMake используется генератор Ninja или Makefiles. В твоих пресетах выбран Ninja, поэтому этот механизм подходит.

Включение:

```bash
-DENABLE_CLANG_TIDY=ON
```

Чтобы диагностика clang-tidy становилась ошибкой сборки:

```bash
-DENABLE_CLANG_TIDY_WARNINGS_AS_ERRORS=ON
```

Эта настройка отличается от `ENABLE_STRICT_ERRORS`: первая управляет предупреждениями clang-tidy, вторая — выбранными предупреждениями GCC/Clang-компилятора.

**Почему в пресете GCC + Clang-Tidy отключён GCC Analyzer.** `-fanalyzer` — параметр GCC, а не предупреждение `-W...`; Clang Frontend не обязан его понимать. Передаваемый clang-tidy параметр `-Wno-unknown-warning-option` подавляет диагностику неизвестных warning-флагов, но не делает GCC-специфичные параметры `-f...` совместимыми с Clang. Поэтому в пресете `gcc-ucrt64-debug-clang-tidy` правильно установлено `ENABLE_GCC_ANALYZER=OFF`.

Clang-tidy не полностью воспроизводит поведение GCC. При анализе GCC-команды Clang использует параметры компиляции проекта, но некоторые GCC-специфичные расширения, опции или особенности реализации могут интерпретироваться иначе. Результаты нужно оценивать с учётом этого различия.

### 4.11. Строгость диагностики clang-tidy

`ENABLE_CLANG_TIDY_WARNINGS_AS_ERRORS=ON` добавляет `--warnings-as-errors=*`. Все предупреждения, выданные проверками clang-tidy, становятся ошибками.

На начальном этапе лучше оставить `OFF`: сначала изучить и устранить полезные замечания, затем включить строгий режим. Эта опция не включает новые проверки — список проверок задаётся в `.clang-tidy`.

```bash
-DENABLE_CLANG_TIDY_WARNINGS_AS_ERRORS=ON
```

### 4.12. Цели clang-format

`ENABLE_CLANG_FORMAT_TARGETS=ON` (по умолчанию включено) просит CMake найти `clang-format` и создать две цели:

- `format` — форматирует найденные файлы и изменяет их (`clang-format -i`);
- `format-check` — проверяет форматирование без изменения файлов (`--dry-run --Werror`).

Текущая реализация включает файлы `*.c` и `*.h` во всём дереве исходников и исключает каталоги `.git`, `out`, `build`, `third_party`, `vendor`. Список формируется при конфигурации CMake; `CONFIGURE_DEPENDS` просит CMake перепроверять glob при последующих сборках, когда набор файлов меняется.

Если `clang-format` не найден, CMake выдаёт предупреждение и цели `format`/`format-check` не создаются. В текущем пресете каталог UCRT64 добавляется в `PATH` на время конфигурации, поэтому отдельный `CLANG_FORMAT_EXECUTABLE` обычно не нужен. При желании путь можно переопределить через `cacheVariables`.

Включение/отключение создания целей:

```bash
-DENABLE_CLANG_FORMAT_TARGETS=ON
-DENABLE_CLANG_FORMAT_TARGETS=OFF
```

## 5. Файл конфигурации `.clang-tidy`

Поскольку текущий `CMakeLists.txt` передаёт clang-tidy аргумент:

```text
--config-file=${PROJECT_SOURCE_DIR}/.clang-tidy
```

в корне проекта должен существовать файл `.clang-tidy`. Это YAML-конфигурация со списком включённых проверок.

Начальный вариант для учебного C-проекта:

```yaml
# Сначала отключаем все проверки, затем включаем выбранные группы.
Checks: >
  -*,
  clang-analyzer-*,
  bugprone-*,
  cert-*,
  portability-*

# Группы modernize-* и cppcoreguidelines-* не включены:
# они преимущественно ориентированы на C++.

# Не превращать предупреждения в ошибки на уровне файла.
# Строгость отдельно управляется ENABLE_CLANG_TIDY_WARNINGS_AS_ERRORS.
WarningsAsErrors: ''

# Показывать диагностику в заголовках проекта.
HeaderFilterRegex: '.*'

# Не анализировать системные заголовки.
SystemHeaders: false

# Для исправлений clang-tidy использовать стиль из .clang-format.
FormatStyle: file
```

Группы `bugprone-*`, `cert-*` и `portability-*` содержат проверки с разной применимостью к C и C++. clang-tidy запускается в режиме C для `.c`-файлов, поэтому набор фактически применимых проверок будет зависеть от версии LLVM и языка конкретной единицы трансляции. Посмотреть доступные проверки можно так:

```powershell
C:\msys64\ucrt64\bin\clang-tidy.exe --list-checks -checks="-*,clang-analyzer-*,bugprone-*,cert-*,portability-*"
```

Перед включением большого набора проверок полезно посмотреть результат на нескольких учебных файлах и постепенно настроить категории. Не следует бездумно включать `modernize-*` или `cppcoreguidelines-*` целиком: значительная часть этих проверок рассчитана на C++.

## 6. Файл конфигурации `.clang-format`

Для `clang-format` в корне проекта создай `.clang-format`. Текущая CMake-цель запускает программу с `--style=file`, поэтому форматтер ищет конфигурационный файл для каждого исходника.

Стартовый вариант:

```yaml
BasedOnStyle: LLVM

# Отступы
IndentWidth: 4
TabWidth: 4
UseTab: Never

# Длина строки
ColumnLimit: 100

# Скобки и короткие конструкции
BreakBeforeBraces: Attach
AllowShortFunctionsOnASingleLine: None
AllowShortIfStatementsOnASingleLine: Never
AllowShortLoopsOnASingleLine: false

# Указатели: int *ptr;
PointerAlignment: Right
DerivePointerAlignment: false

# Выравнивание
AlignAfterOpenBracket: Align
AlignOperands: Align

# Подключаемые заголовки
SortIncludes: true

# Пробелы перед скобками управляющих конструкций
SpaceBeforeParens: ControlStatements
```

Это пример компактного профиля. В загруженном `.clang-format` хранится более полный набор настроек, полученный из `clang-format -dump-config`. Он содержит некоторые параметры, появившиеся в clang-format 20, поэтому текущий файл требует **clang-format 20 или новее**. В `CMakeLists.txt` добавлена ранняя проверка версии инструмента. Важно хранить `.clang-format` в системе контроля версий, чтобы форматирование было одинаковым на всех компьютерах.

В фактическом `.clang-format` используется `BreakBeforeBraces: Allman`. Блок `BraceWrapping` в таком режиме не действует: его параметры учитываются только при `BreakBeforeBraces: Custom`, поэтому неиспользуемый блок удалён. `InsertNewlineAtEOF: true` согласован с предупреждением Clang `-Wnewline-eof` и просит форматтер сохранять завершающий перевод строки.

## 7. Как запускать clang-tidy

### 7.1. Автоматически при сборке

Для твоего пресета `gcc-ucrt64-debug-clang-tidy`:

```powershell
cmake --preset gcc-ucrt64-debug-clang-tidy
cmake --build out/build/gcc-ucrt64-debug-clang-tidy --parallel
```

При компиляции C-файлов CMake запускает clang-tidy вместе с компилятором. Если исходный файл не требуется перекомпилировать, Ninja может не запускать для него clang-tidy повторно. Чтобы выполнить полную пересборку и повторный анализ:

```powershell
cmake --build out/build/gcc-ucrt64-debug-clang-tidy --clean-first --parallel
```

Автоматическая интеграция `CMAKE_C_CLANG_TIDY` получает от CMake путь исходного файла и команду компиляции. Для этого режима `compile_commands.json` не является обязательным.

### 7.2. Вручную по базе команд компиляции

Во втором пресете включено:

```json
"CMAKE_EXPORT_COMPILE_COMMANDS": "ON"
```

Для Ninja CMake создаёт файл:

```text
out/build/gcc-ucrt64-debug-clang-tidy/compile_commands.json
```

Он позволяет запускать clang-tidy отдельно от сборки:

```powershell
clang-tidy `
    -p "out/build/gcc-ucrt64-debug-clang-tidy" `
    "hw_1/main.c"
```

Параметр `-p` указывает каталог, в котором находится `compile_commands.json`. Этот способ удобен, когда нужно проверить один файл, не перестраивая весь проект.

`CMAKE_EXPORT_COMPILE_COMMANDS=ON` полезен для ручного запуска clang-tidy и инструментов вроде clangd. Для встроенного запуска через `CMAKE_C_CLANG_TIDY` он сам по себе не обязателен.

### 7.3. Исправление кода

clang-tidy поддерживает `--fix`, который применяет автоматические исправления, если соответствующая проверка предоставляет fix-it:

```powershell
clang-tidy `
    -p "out/build/gcc-ucrt64-debug-clang-tidy" `
    --fix `
    "hw_1/main.c"
```

Используй `--fix` осознанно: после применения исправлений обязательно просмотри diff и повторно собери проект. Не включай автоматическое исправление в обычную сборку без необходимости.

## 8. Как запускать clang-format

После конфигурации CMake, если `clang-format` найден, доступны две цели.

### 8.1. Отформатировать исходники

```powershell
cmake --build out/build/gcc-ucrt64-debug-clang-tidy --target format
```

Команда изменяет все найденные `*.c` и `*.h` в дереве проекта с учётом исключённых каталогов.

### 8.2. Только проверить форматирование

```powershell
cmake --build out/build/gcc-ucrt64-debug-clang-tidy --target format-check
```

Команда использует `--dry-run --Werror`, поэтому файлы не меняются. Если форматирование не соответствует `.clang-format`, цель завершается с ошибкой.

### 8.3. Проверить, что CMake создал цели

Можно вывести доступные цели генератора:

```powershell
cmake --build out/build/gcc-ucrt64-debug-clang-tidy --target help
```

Если `format` и `format-check` отсутствуют, проверь сообщение конфигурации `clang-format was not found`, значение `ENABLE_CLANG_FORMAT_TARGETS` и путь `CLANG_FORMAT_EXECUTABLE` в CMake cache.

## 9. Настройка CMakePresets.json для MSYS2 UCRT64

В загруженном `CMakePresets.json` есть два пресета:

1. GCC UCRT64 — обычная строгая сборка с GCC Analyzer;
2. GCC UCRT64 + Clang-Tidy — сборка GCC с дополнительным анализом clang-tidy.

### 9.1. Что уже настроено правильно

Во втором пресете заданы:

```json
"CMAKE_EXPORT_COMPILE_COMMANDS": "ON",
"ENABLE_GCC_ANALYZER": "OFF",
"ENABLE_CLANG_TIDY": "ON",
"ENABLE_CLANG_TIDY_WARNINGS_AS_ERRORS": "OFF"
```

Это соответствует текущему CMake-файлу. `ENABLE_GCC_ANALYZER=OFF` важен: Clang-Tidy использует Clang Frontend и не обязан понимать GCC-специфичный `-fanalyzer`. `CMAKE_EXPORT_COMPILE_COMMANDS=ON` позволяет запускать анализатор вручную с `-p`; для встроенного запуска через `CMAKE_C_CLANG_TIDY` эта база не обязательна.

В пресетах намеренно не указаны `CLANG_TIDY_EXECUTABLE` и `CLANG_FORMAT_EXECUTABLE`: обе программы находятся через `find_program()` и `PATH`.

### 9.2. Как найти LLVM-инструменты через PATH без глобального PATH Windows

В текущих пресетах нужно добавить на верхнем уровне каждого `configurePreset` (рядом с `cacheVariables`):

```json
"environment": {
    "PATH": "C:/msys64/ucrt64/bin${pathListSep}$penv{PATH}"
}
```

Это добавляет `C:/msys64/ucrt64/bin` в начало `PATH` только для процесса конфигурации данного пресета и сохраняет унаследованный `PATH`. В `CMakeLists.txt` при этом не нужны `HINTS` и абсолютные пути.

Такой вариант:
- позволяет `find_program()` найти `clang-tidy` и `clang-format`;
- не требует добавлять UCRT64 в глобальный `PATH` Windows;
- не добавляет CLANG64 и не смешивает два окружения MSYS2.

Если UCRT64 уже присутствует в `PATH`, блок `environment` необязателен. Альтернатива — задать `CMAKE_PROGRAM_PATH` в `cacheVariables`, если нужно влиять только на поиск программ CMake, а не на окружение всего процесса.

### 9.3. Ограничение CMake Presets schema version 8

В файле используется `"version": 8`. Эта версия схемы Presets появилась в **CMake 3.28**. Поэтому в корневой объект `CMakePresets.json` добавлено:

```json
"cmakeMinimumRequired": {
    "major": 3,
    "minor": 28,
    "patch": 0
}
```

`cmake_minimum_required(VERSION 3.13)` в `CMakeLists.txt` можно оставить, если важно сохранить возможность конфигурировать проект напрямую без Presets на более старом CMake. Но для использования именно `CMakePresets.json` версии 8 нужен CMake не ниже 3.28.

### 9.4. CMake C++ compiler

Корневой проект объявляет только язык C:

```cmake
project(c_language_basics VERSION 0.1.0 LANGUAGES C)
```

Поэтому `CMAKE_CXX_COMPILER` из первого пресета не используется и удалён. Если проект в будущем начнёт содержать C++, добавь `CXX` в `LANGUAGES` и настрой компилятор C++ отдельно.

### 9.5. Рекомендуемые настройки пресетов

Обычный GCC UCRT64:

```json
{
    "name": "GCC 16.2.0 x86_64-w64-mingw32 (ucrt64)",
    "generator": "Ninja",
    "binaryDir": "${sourceDir}/out/build/${presetName}",
    "environment": {
        "PATH": "C:/msys64/ucrt64/bin${pathListSep}$penv{PATH}"
    },
    "cacheVariables": {
        "CMAKE_C_COMPILER": "C:/msys64/ucrt64/bin/gcc.exe",
        "CMAKE_BUILD_TYPE": "Debug",
        "ENABLE_GCC_ANALYZER": "ON",
        "ENABLE_CLANG_TIDY": "OFF",
        "ENABLE_CLANG_FORMAT_TARGETS": "ON",
        "ENABLE_STRICT_ERRORS": "ON",
        "ENABLE_AGGRESSIVE_GCC_WARNINGS": "ON",
        "ENABLE_SANITIZERS": "OFF"
    }
}
```

GCC UCRT64 + Clang-Tidy:

```json
{
    "name": "gcc-ucrt64-debug-clang-tidy",
    "generator": "Ninja",
    "binaryDir": "${sourceDir}/out/build/${presetName}",
    "environment": {
        "PATH": "C:/msys64/ucrt64/bin${pathListSep}$penv{PATH}"
    },
    "cacheVariables": {
        "CMAKE_C_COMPILER": "C:/msys64/ucrt64/bin/gcc.exe",
        "CMAKE_BUILD_TYPE": "Debug",
        "CMAKE_EXPORT_COMPILE_COMMANDS": "ON",
        "ENABLE_GCC_ANALYZER": "OFF",
        "ENABLE_CLANG_TIDY": "ON",
        "ENABLE_CLANG_TIDY_WARNINGS_AS_ERRORS": "OFF",
        "ENABLE_CLANG_FORMAT_TARGETS": "ON",
        "ENABLE_STRICT_ERRORS": "ON",
        "ENABLE_AGGRESSIVE_GCC_WARNINGS": "ON",
        "ENABLE_SANITIZERS": "OFF"
    }
}
```

В реальном файле сохрани также `CMAKE_INSTALL_PREFIX` и `displayName`, если они нужны. Значения `CLANG_TIDY_EXECUTABLE` и `CLANG_FORMAT_EXECUTABLE` можно добавить вручную только при необходимости переопределить поиск через PATH.

После изменения пресета выбери его в VS Code или выполни:

```powershell
cmake --preset gcc-ucrt64-debug-clang-tidy
```

## 10. Установка инструментов в MSYS2 UCRT64

Если используешь пакетный менеджер MSYS2, в терминале UCRT64 установи набор LLVM tools:

```bash
pacman -S --needed mingw-w64-ucrt-x86_64-clang-tools-extra
```

Пакет `clang-tools-extra` предоставляет `clang-tidy` и зависит от соответствующего пакета Clang; `clang-format.exe` устанавливается пакетом Clang. После установки проверь программы из PowerShell:

```powershell
& "C:/msys64/ucrt64/bin/clang-tidy.exe" --version
& "C:/msys64/ucrt64/bin/clang-format.exe" --version
```

В пресетах каталог UCRT64 добавляется в `PATH` только для процесса конфигурации. Не добавляй одновременно UCRT64 и CLANG64 в глобальный `PATH` Windows. Для данного GCC-пресета используй согласованное окружение UCRT64. Если запускаешь инструменты вручную из обычного PowerShell, активируй UCRT64 в `PATH` текущего терминала либо укажи полный путь к exe.

## 11. Примеры команд

### 11.1. Обычная сборка GCC

```powershell
cmake --preset "GCC 16.2.0 x86_64-w64-mingw32 (ucrt64)"
cmake --build "out/build/GCC 16.2.0 x86_64-w64-mingw32 (ucrt64)" --parallel
```

В этом режиме применяются общие и GCC-предупреждения, а `-fanalyzer` включён по умолчанию. Clang-Tidy выключен.

### 11.2. GCC со строгими предупреждениями и Clang-Tidy

```powershell
cmake --preset gcc-ucrt64-debug-clang-tidy
cmake --build out/build/gcc-ucrt64-debug-clang-tidy --parallel
```

### 11.3. GCC UCRT64 и санитайзеры

В твоём текущем окружении MSYS2 UCRT64 GCC проверка `-fsanitize=address,undefined` завершилась неудачно. Поэтому не включай `ENABLE_SANITIZERS=ON` в этом пресете: CMake корректно остановит конфигурацию с диагностикой. Используй этот пресет без санитайзеров либо отдельный toolchain, который проходит проверку.

### 11.4. Clang CLANG64 с санитайзерами

Если установлен Clang CLANG64 и его набор санитайзеров проходит тест компиляции/линковки, можно создать отдельный каталог сборки:

```powershell
cmake -S . -B out/build/clang64-debug-sanitizers -G Ninja `
    -DCMAKE_C_COMPILER=C:/msys64/clang64/bin/clang.exe `
    -DCMAKE_BUILD_TYPE=Debug `
    -DENABLE_GCC_ANALYZER=OFF `
    -DENABLE_SANITIZERS=ON

cmake --build out/build/clang64-debug-sanitizers --parallel
```

Если проверка санитайзеров не проходит, изучи `CMakeFiles/CMakeError.log` в каталоге сборки. Не следует считать наличие флага `-fsanitize` доказательством наличия нужного runtime на конкретной платформе.

### 11.5. Подробный вывод команд компиляции

`VERBOSE=1` не является флагом GCC/Clang и не должен находиться в `target_compile_options()`.

Для подробного вывода используй:

```powershell
cmake --build out/build/gcc-ucrt64-debug-clang-tidy --verbose
```

## 12. Важные правила работы с CMake cache

1. Один каталог сборки (`binaryDir`) должен использовать один выбранный C-компилятор и один toolchain. Для перехода с GCC на Clang создай новый каталог сборки.
2. Значения `option()` и переменных путей, переданных через пресет, сохраняются в `CMakeCache.txt`. Повторная конфигурация без нового значения сохраняет предыдущее.
3. Чтобы выключить опцию, явно передай `-DИМЯ=OFF` или измени `cacheVariables` пресета.
4. Чтобы увидеть cache-переменные, выполни `cmake -LA -N <каталог-сборки>`.
5. После изменения `CMakeLists.txt`, `.clang-tidy`, `.clang-format` или `CMakePresets.json` повторно сконфигурируй проект, когда меняются параметры CMake. Изменение только содержимого `.clang-tidy` или `.clang-format` не требует смены компилятора или удаления каталога сборки.
6. Не смешивай разные окружения MSYS2 в одном каталоге сборки. Для UCRT64 и CLANG64 используй отдельные `binaryDir` и согласованные пути к инструментам/runtime.
7. `find_program()` сохраняет найденные `CLANG_TIDY_EXECUTABLE` и `CLANG_FORMAT_EXECUTABLE` в CMake cache. Если ты изменил `PATH` или переместил LLVM, удали старые cache-значения (в VS Code — **CMake: Delete Cache and Reconfigure**, либо через `cmake -U CLANG_TIDY_EXECUTABLE -U CLANG_FORMAT_EXECUTABLE ...`), чтобы поиск выполнился заново.

## 13. Ограничения и особенности

- Профиль предупреждений рассчитан на идентификаторы CMake `GNU` и `Clang`. `AppleClang` имеет отдельный идентификатор и сейчас не охвачен соответствующими generator expressions.
- `CMAKE_C_CLANG_TIDY` поддерживается CMake для генераторов Ninja и Makefile. В этом проекте используется Ninja.
- Текущий `.clang-format` содержит параметры, появившиеся в clang-format 20; поэтому `clang-format` должен быть версии 20 или новее. Для согласованности используй `clang-tidy` той же версии LLVM. CMake проверяет версию найденных инструментов при включении соответствующих функций.
- clang-tidy разбирает код Clang Frontend. При использовании базы GCC-команд часть специфичных параметров GCC может быть неизвестна Clang. `--extra-arg=-Wno-unknown-warning-option` помогает с неизвестными warning-флагами, но не делает все параметры GCC совместимыми.
- `-fanalyzer` — GCC-специфичная опция. Поэтому текущий GCC + Clang-Tidy пресет отключает `ENABLE_GCC_ANALYZER`.
- `CMAKE_EXPORT_COMPILE_COMMANDS=ON` создаёт базу команд компиляции для Ninja/Makefile. Она нужна для ручного запуска clang-tidy с `-p` и полезна clangd; встроенному вызову `CMAKE_C_CLANG_TIDY` сама база не обязательна.
- clang-tidy запускается для файлов, которые проходят через компиляцию соответствующих C-целей. При инкрементальной сборке неизменённые файлы могут не анализироваться повторно; для полного повторного запуска можно выполнить `--clean-first` или использовать ручной запуск с compile database.
- clang-format форматирует только найденные `*.c` и `*.h`; другие расширения, например `.inc`, в текущий glob не входят. Если добавишь новые типы файлов, расширь список в `file(GLOB_RECURSE ...)`.
- `format` изменяет файлы. Перед запуском желательно сохранить изменения в системе контроля версий или проверить `git diff` после форматирования.
- Санитайзеры находят ошибки только на реально выполненных путях. Отсутствие диагностик не доказывает отсутствие дефектов.
- Некоторые предупреждения лучше работают с `-O1`/`-O2`; полезно иметь отдельную оптимизированную диагностическую сборку.
- Успешная проверка `CheckCCompilerFlag` означает, что пробная компиляция (а в блоке санитайзеров и линковка) прошла с параметром. Она не гарантирует, что проверка обнаружит каждый соответствующий дефект в реальной программе.

## 14. Быстрая памятка

| Задача | Настройка или команда |
|---|---|
| Выключить GCC Analyzer | `-DENABLE_GCC_ANALYZER=OFF` |
| Включить Clang unsafe buffer diagnostics | `-DENABLE_CLANG_UNSAFE_BUFFER=ON` |
| Включить строгие ошибки компилятора | `-DENABLE_STRICT_ERRORS=ON` |
| Запретить VLA | `-DDISABLE_VLA=ON` |
| Включить проверки совместимости C | `-DENABLE_C_COMPAT_WARNINGS=ON` |
| Включить агрессивные проверки GCC | `-DENABLE_AGGRESSIVE_GCC_WARNINGS=ON` |
| Включить ASan/UBSan (и Clang Integer Sanitizer) | `-DENABLE_SANITIZERS=ON` |
| Включить clang-tidy при сборке | `-DENABLE_CLANG_TIDY=ON` |
| Сделать предупреждения clang-tidy ошибками | `-DENABLE_CLANG_TIDY_WARNINGS_AS_ERRORS=ON` |
| Создать цели форматирования | `-DENABLE_CLANG_FORMAT_TARGETS=ON` |
| Форматировать исходники | `cmake --build <build-dir> --target format` |
| Проверить форматирование | `cmake --build <build-dir> --target format-check` |
| Запустить clang-tidy вручную | `clang-tidy -p <build-dir> <source.c>` |

Все опции можно комбинировать, если они применимы к выбранному компилятору и целевой платформе. Для твоего текущего MSYS2 UCRT64 пресета оставляй санитайзеры выключенными, пока проверка CMake не проходит успешно.

## 15. Официальная документация

- [CMake: `CMAKE_C_CLANG_TIDY`](https://cmake.org/cmake/help/latest/variable/CMAKE_LANG_CLANG_TIDY.html)
- [CMake: свойство `C_CLANG_TIDY`](https://cmake.org/cmake/help/latest/prop_tgt/LANG_CLANG_TIDY.html)
- [CMake: `CMAKE_EXPORT_COMPILE_COMMANDS`](https://cmake.org/cmake/help/latest/variable/CMAKE_EXPORT_COMPILE_COMMANDS.html)
- [LLVM: clang-tidy](https://clang.llvm.org/extra/clang-tidy/)
- [LLVM: clang-format](https://clang.llvm.org/docs/ClangFormat.html)
- [MSYS2: пакет clang-tools-extra для UCRT64](https://packages.msys2.org/packages/mingw-w64-ucrt-x86_64-clang-tools-extra)
- [MSYS2: пакет Clang для UCRT64](https://packages.msys2.org/packages/mingw-w64-ucrt-x86_64-clang)
