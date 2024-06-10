FROM emscripten/emsdk:2.0.22

RUN apt-get update && apt-get install -y \
    build-essential \
    cmake \
    git \
    wget \
    nginx \
    libwayland-dev \
    libx11-dev \
    libxrandr-dev \
    libxi-dev \
    libxcursor-dev \
    libgl1-mesa-dev \
    libglu1-mesa-dev \
    libxkbcommon-dev \
    libxinerama-dev

RUN git clone https://github.com/raysan5/raylib.git /raylib

WORKDIR /raylib/src
RUN emmake make PLATFORM=PLATFORM_WEB

WORKDIR /app
COPY src /app/src
COPY include /app/include
COPY makefile /app

RUN emcc src/main.cpp src/object.cpp src/hero.cpp src/map.cpp src/ground.cpp src/cell.cpp src/gameManager.cpp src/item.cpp src/inventory.cpp -o /app/index.html -I /raylib/src -L /raylib/src -lraylib \
    -s USE_GLFW=3 -s FULL_ES2=1 -s WASM=1 -s ALLOW_MEMORY_GROWTH=1 \
    -s EXPORTED_FUNCTIONS='["_main", "_glfwSetWindowContentScaleCallback"]' \
    -s ERROR_ON_UNDEFINED_SYMBOLS=0 \
    -s EXTRA_EXPORTED_RUNTIME_METHODS='["ccall", "cwrap"]' \
    -s ASYNCIFY \
    --preload-file . -s LLD_REPORT_UNDEFINED=1


RUN cp /app/index.html /usr/share/nginx/html/index.html
RUN cp /app/index.js /usr/share/nginx/html/index.js
RUN cp /app/index.wasm /usr/share/nginx/html/index.wasm
RUN cp /app/index.data /usr/share/nginx/html/index.data

RUN echo "daemon off;" >> /etc/nginx/nginx.conf

COPY default.conf /etc/nginx/conf.d/default.conf


EXPOSE 80

CMD ["nginx"]