#include "main.h"

// A graphical application consists of an SDL_Renderer
// and an SDL_Window. We'll manipulate both through
// their pointers. The actual `objects' are built
// in memory using functions:
//
// SDL_Window is constructed by calling `SDL_CreateWindow()'
// Its declaration is ONLY available in the SDL library source code,
// not in development libs, because its internals are platform-specific.
// Since its internal structure is useless to developers, it
// is hidden.
//
// SDL_Renderer is constructed by calling `SDL_CreateRenderer()'
// More info: https://wiki.libsdl.org/SDL_Renderer
//
// These structures are created globally, because when passing them
// to functions we'll either need pointer-to-pointer or a function
// pointer that is unable to take arguments. We'll perfect this
// later on, because you should avoid globals whenever you are able...

SDL_Window *window = NULL;
SDL_Renderer *renderer = NULL;

int main(void)
{
    

    window = createWindow("Hello SDL2 in C", SCREEN_WIDTH, SCREEN_HEIGHT);

    rgbaStruct_t color = {120, 144, 156, 125};

    renderer = createRenderer(window, color);

    while (1)
    {
        SDL_SetRenderDrawColor(renderer, 120, 144, 156, 255);
        SDL_RenderClear(renderer);
        
        process_input();

        int squareSize = 90;
        rgbaStruct_t color1 = {255, 0, 0, 75};
        drawRect(renderer, SCREEN_WIDTH / 2 - squareSize, SCREEN_HEIGHT / 2 - squareSize, squareSize, squareSize, color1, 1);
        drawRect(renderer, SCREEN_WIDTH / 2 - squareSize, SCREEN_HEIGHT / 2 + squareSize, squareSize, squareSize, color1, 0);

        SDL_RenderPresent(renderer);

        SDL_Delay(16);
    }

    return 0;
}

void process_input(void)
{

    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_QUIT:
            proper_shutdown();
            exit(0);
            break;
        case SDL_KEYDOWN:
            // https://wiki.libsdl.org/CategoryKeyboard
            // https://wiki.libsdl.org/SDL_Scancode
            if (event.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
            {
                proper_shutdown();
                exit(0);
            }
            break;
        default:
            break;
        }
    }
}

void proper_shutdown(void)
{
    // Make sure to look up these functions @
    // https://wiki.libsdl.org/CategoryAPI
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}