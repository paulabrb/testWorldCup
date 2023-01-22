cmake_minimum_required(VERSION 3.11)

project(game)

include_directories(include)

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

include_directories(${SDL2_INCLUDE_DIRS} ${SDL2IMAGE_INCLUDE_DIR})

#modified
add_executable(Game apps/main.cpp src/Game.cpp src/TextureManager.cpp)

target_link_libraries(Game ${SDL2_LIBRARIES} ${SDL2IMAGE_LIBRARY})

target_compile_options(Game PUBLIC -Wall -lSDL2 -lSDL2_image)
