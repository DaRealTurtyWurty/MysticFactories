cmake_minimum_required(VERSION 3.28)
project(MysticFactories)

include_directories("D:/CPP-Libs/SDL2-2.30.2/include")
include_directories("D:/CPP-Libs/SDL2_image-2.8.2/include")
include_directories("D:/CPP-Libs/SDL2_ttf-2.22.0/include")

set(CMAKE_CXX_STANDARD 17)

add_executable(MysticFactories main.cpp
        Constants.h
        renderer/Text.h
        world/World.cpp
        world/World.h
        world/Chunk.cpp
        world/Chunk.h
        world/entity/Entity.cpp
        world/entity/Entity.h
        renderer/WorldRenderer.cpp
        renderer/WorldRenderer.h
        world/entity/Player.cpp
        world/entity/Player.h)

target_link_libraries(MysticFactories "D:/CPP-Libs/SDL2-2.30.2/lib/x64/SDL2.lib")
target_link_libraries(MysticFactories "D:/CPP-Libs/SDL2_image-2.8.2/lib/x64/SDL2_image.lib")
target_link_libraries(MysticFactories "D:/CPP-Libs/SDL2_ttf-2.22.0/lib/x64/SDL2_ttf.lib")