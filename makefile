CC = emcc
CFLAGS = -I/raylib/src -L/raylib/src -lraylib -s USE_GLFW=3 -s FULL_ES2=1 -s WASM=1 -s ALLOW_MEMORY_GROWTH=1 --preload-file .
SOURCES = src/main.cpp src/object.cpp src/hero.cpp src/map.cpp src/ground.cpp src/cell.cpp src/gameManager.cpp src/item.cpp src/inventory.cpp
TARGET = index.html

all:
	$(CC) $(CFLAGS) $(SOURCES) -o $(TARGET)