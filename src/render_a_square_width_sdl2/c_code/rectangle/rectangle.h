#ifndef SQUARE_H
#define SQUARE_H

#include <SDL2/SDL.h> // SDL_* functions, enum values and structs

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
 * @param blendColors 0 means false and 1 means true
 * whene true the colors are blended (alphe channels plays a role with the existing layers)
 */
void drawRect(SDL_Renderer *renderer, int x, int y, int w, int h, rgbaStruct_t squareColor, int blendColors);

#endif