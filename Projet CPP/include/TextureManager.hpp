#pragma once

#include "Game.hpp"
#include "/opt/homebrew/include/SDL2/SDL.h"
#include "/opt/homebrew/include/SDL2/SDL_image.h"

class TextureManager{

public:
    static SDL_Texture* LoadTexture(const char* fileName, SDL_Renderer* ren);

};