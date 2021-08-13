#pragma once

#include <iostream>
#include <string>

#include <SDL2/SDL.h> // SDL_* functions, enum values and structs
#include <SDL2/SDL_image.h>

class Texture
{
protected:
    SDL_Texture *txtr = NULL;
    SDL_Renderer *renderer = NULL;
    int x;
    int y;
    float angle;
    int width;
    int height;


    /**
     * @brief loads the png/jpg and makes a texture
     * @param filename path to the image in linux style ex. gfx/myImge.png
     **/
    void load_texture(char *filename);

public:
    Texture(SDL_Renderer *renderer, int x, int y, char *filename);
    ~Texture();
    virtual void render();
};