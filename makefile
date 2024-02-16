CC = g++
CFLAGS = -std=c++20 -Iinclude -Isrc -g
LDFLAGS =  -framework CoreVideo -framework IOKit -framework Cocoa -framework GLUT -framework OpenGL lib/libraylib.a
PATH_LIBRARY = lib

TARGET = main
SOURCES = main.cpp \
          utils/object/object.cpp \
          utils/ground/ground.cpp \
          utils/cell/cell.cpp \
          utils/map/map.cpp \
		  utils/hero/hero.cpp \
		  utils/item/item.cpp \
		  utils/item/copperItem.cpp \
		  utils/item/ironItem.cpp \
		  utils/inventory/inventory.cpp \
		  utils/gameManager/gameManager.cpp

OBJECTS = $(SOURCES:.cpp=.o)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) $(LDFLAGS) -o $(TARGET)

.cpp.o:
	$(CC) $(CFLAGS) $< -c -o $@

clean:
	rm -f $(OBJECTS) $(TARGET)

