#include "../include/TextureManager.hpp"

SDL_Texture* TextureManager:: IMG_LoadTexture(const char* texture,SDl_Renderer* ren)
{
    //Create a surface
    SDL_Surface* tempSurface=IMG_Load(texture);
    SDL_Texture* tex=SDL_CreateTextureFromSurface(ren,tempSurface);
    //Clear
    SDL_FreeSurface(tempSurface);

    return tex;
    
}
