#include "screen.h"

SDL_Window *createWindow(const char *screenName, const int screenWidth, const int screenHeight)
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("Couldn't initialize SDL: %s\n", SDL_GetError());
        // Let the OS know shit went sideways when closing this program:
        exit(1);
    }
    SDL_Window *window = NULL;

    window = SDL_CreateWindow((char *)screenName, SDL_WINDOWPOS_CENTERED,
                              SDL_WINDOWPOS_CENTERED, screenWidth, screenHeight,
                              SDL_WINDOW_ALLOW_HIGHDPI);
    if (window == NULL) // error handling:
    {
        printf("Failed to create window -- Error: %s\n", SDL_GetError());
        // Let the OS know shit went sideways when closing this program:
        exit(1);
    }

    return window;
};

SDL_Renderer *createRenderer(SDL_Window *window, rgbaStruct_t backgroundColor)
{
    SDL_Renderer *renderer = NULL;

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL)
    {
        printf("Failed to create renderer -- Error: %s\n", SDL_GetError());
        // Let the OS know shit went sideways when closing this program:
        exit(1);
    }

    SDL_SetRenderDrawColor(renderer, backgroundColor.r, backgroundColor.g, backgroundColor.b, backgroundColor.a);
    SDL_RenderClear(renderer);

    return renderer;
};