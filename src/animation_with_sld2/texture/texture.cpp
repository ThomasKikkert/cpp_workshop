#include "texture.hpp"

Texture::~Texture()
{
    if (txtr)
    {
        SDL_DestroyTexture(txtr);
        txtr = NULL;
    }
}

void Texture::load_texture(char *filename)
{
    if (renderer)
    {
        if (txtr)
        {
            SDL_DestroyTexture(txtr);
            txtr = NULL;
        }
        txtr = IMG_LoadTexture(renderer, filename);

        if (!txtr)
        {
            std::cout << "can't create a texture: " << txtr << "\n";
            std::cout << "error: " << IMG_GetError() << "\n";
        }
    }
    else
    {
        throw("the renderer was not set");
    }
}

void Texture::load_texture(char *filename, SDL_Texture *texture)
{
    if (renderer)
    {
        if (texture)
        {
            SDL_DestroyTexture(texture);
            texture = NULL;
        }
        texture = IMG_LoadTexture(renderer, filename);
        if (!texture)
        {
            std::cout << "can't create a texture: " << texture << "\n";
            std::cout << "error: " << IMG_GetError() << "\n";
        }
    }
    else
    {
        throw("the renderer was not set");
    }
}



void Texture::render()
{
    SDL_Rect dest;
    dest.x = x;
    dest.y = y;

    SDL_QueryTexture(txtr, NULL, NULL, &dest.w, &dest.h);
    SDL_RenderCopy(renderer, txtr, NULL, &dest);
}