cmake_minimum_required(VERSION 3.26)
project(factorio)

set(CMAKE_CXX_STANDARD 23)

include_directories(utils/cell)
include_directories(utils/ground)
include_directories(utils/hero)
include_directories(utils/map)
include_directories(utils/object)
include_directories(utils/item)
include_directories(utils/inventory)
include_directories(utils/opt)
include_directories(utils/ores)
include_directories(utils/gameManager)



add_executable(factorio
        "main.cpp"
)
