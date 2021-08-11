#include "rectangle.h"

void drawRect(SDL_Renderer *renderer, int x, int y, int w, int h, rgbaStruct_t squareColor, int blendColors)
{
    SDL_Rect rect;
    rect.x = x;
    rect.y = y;
    rect.w = w;
    rect.h = h;

    SDL_SetRenderDrawColor(renderer, squareColor.r, squareColor.g, squareColor.b, squareColor.a);

    if (blendColors)
    {
        SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);        
    }

    SDL_RenderFillRect(renderer, &rect);

    if (blendColors)
    {
        SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_NONE);        
    }
}