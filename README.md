# Factorio
Наша игра сделана на основе популярной 2D-песочницы. Используя свои креативные способности 
вы можете добывать ресурсы и развивать инфраструктуру. На данный момент в проекте реализовано:
- передвижение по карте (на клавишах `WASD`)
- ресурсы (в правой части экрана указаны ресурсы, находящиеся в клетке, на которой стоит персонаж, и их количество)
- инвентарь (клавиша `E` кладет ресурс в инвентарь, расположенный в нижней части экрана)

## Запуск
Для запуска игры необходимо клонировать к себе репозиторий. Необходимо установить к себе на устроиство
также [EmScripten](https://emscripten.org/docs/getting_started/downloads.html) и библиотеку [RayLib](https://www.raylib.com/index.html). Далее через консоль переходим в папку 
проекта и собираем проект с помощью make-файла, нужно написать команду `mingw32-make` (для Windows) и `make` (для Unix ос).
После этого проект сразу же откроется на локальном сервере.

## Стек технологий
- Docker
- Nginx
- RayLib
- WebAssembly
- Emscripten

