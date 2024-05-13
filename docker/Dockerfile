FROM trzeci/emscripten AS emscripten

# COPY src/ /src/
# COPY include/ /include/
COPY test.cpp /src

# RUN git clone https://github.com/raysan5/raylib.git
# WORKDIR /raylib/src
# RUN make PLATFORM=PLATFORM_WEB

RUN emcc /src/test.cpp -o /src/index.html


FROM nginx

WORKDIR /usr/share/nginx/html

COPY --from=emscripten /src/index.html /usr/share/nginx/html
COPY --from=emscripten /src/index.wasm /usr/share/nginx/html
COPY --from=emscripten /src/index.js /usr/share/nginx/html

COPY default.conf /etc/nginx/conf.d/default.conf

EXPOSE 80
