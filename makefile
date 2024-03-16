CC = emcc
CFLAGS = -Wall -std=c++20 -D_DEFAULT_SOURCE -Wno-missing-braces -Wunused-result -Os -I. -I raylib/src -I raylib/src/external
LDFLAGS = -L. -L raylib/src
LIBS = -s USE_GLFW=3 -s ASYNCIFY -s TOTAL_MEMORY=67108864 -s FORCE_FILESYSTEM=1 --shell-file raylib/src/shell.html raylib/src/libraylib.a -DPLATFORM_WEB -s EXPORTED_RUNTIME_METHODS=ccall

all: clean index.html run

index.html: src/main.cpp src/object.cpp src/hero.cpp src/map.cpp src/ground.cpp src/cell.cpp src/gameManager.cpp src/item.cpp src/inventory.cpp
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS) $(LIBS)

clean:
	rm -f *.js *.wasm index.html 

run:
	emrun index.html
