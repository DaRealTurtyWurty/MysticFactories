cmake_minimum_required(VERSION 3.28)
project(MysticFactories)

include_directories("F:/CPP-Libs/SDL2/include")
include_directories("F:/CPP-Libs/SDL2_image/include")
include_directories("F:/CPP-Libs/SDL2_ttf/include")

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
        world/entity/Player.h
        renderer/Texture.h
        world/ChunkGenerator.cpp
        world/ChunkGenerator.h
        world/tile/TileType.h
        world/tile/TileData.h
        math/Vector2f.h
        renderer/Camera.cpp
        renderer/Camera.h
        math/Random.h
        math/Random.cpp
        noise/PerlinNoise.h
)

target_link_libraries(MysticFactories "F:/CPP-Libs/SDL2/lib/x64/SDL2.lib")
target_link_libraries(MysticFactories "F:/CPP-Libs/SDL2_image/lib/x64/SDL2_image.lib")
target_link_libraries(MysticFactories "F:/CPP-Libs/SDL2_ttf/lib/x64/SDL2_ttf.lib")