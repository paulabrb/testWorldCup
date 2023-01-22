#include "../include/TextureManager.hpp"
#include "/opt/homebrew/include/SDL2/SDL.h"
#include "/opt/homebrew/include/SDL2/SDL_image.h"
SDL_Texture* TextureManager:: LoadTexture(const char* texture,SDL_Renderer* ren)
{
    //Create a surface
    SDL_Surface* tempSurface=IMG_Load(texture);
    SDL_Texture* tex=SDL_CreateTextureFromSurface(ren,tempSurface);
    //Clear
    SDL_FreeSurface(tempSurface);

    return tex;
    
}
