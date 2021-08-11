#ifndef SCREEN_H
#define SCREEN_H

#include <stdio.h>
#include <SDL2/SDL.h> // SDL_* functions, enum values and structs

#define SCREEN_WIDTH (int)1280
#define SCREEN_HEIGHT (int)720

// prefents dubble definition of the struct
// big change its is need more than ones
#ifndef RGBA_STRUCT
#define RGBA_STRUCT

typedef struct _rgba_
{
    unsigned char r;
    unsigned char g;
    unsigned char b;
    unsigned char a;
} rgbaStruct_t;

#endif

/**
* @brief creates the window with the given size en caption given text above
*/
SDL_Window *createWindow(const char *screenName, const int screenWidth, const int screenHeight);

/**
* @brief creates the renderer with the given color
*/
SDL_Renderer *createRenderer(SDL_Window *window, rgbaStruct_t backgroundColor);

#endif