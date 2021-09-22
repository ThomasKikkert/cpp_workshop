#include "screen.hpp"

Screen::Screen(std::string windowName, int screenWidth, int screenHeight, uint32_t *startingTick)
{
    this->startingTick = startingTick;
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) < 0)
    {
        std::cout << "Couldn't initialize SDL: " << SDL_GetError() << "\n";
        // Let the OS know shit went sideways when closing this program:
        exit(1);
    }

    this->window = SDL_CreateWindow(windowName.c_str(), SDL_WINDOWPOS_CENTERED,
                                    SDL_WINDOWPOS_CENTERED, screenWidth, screenHeight,
                                    SDL_WINDOW_ALLOW_HIGHDPI);
    if (this->window == NULL) // error handling:
    {
        std::cout << "Failed to create window -- Error: " << SDL_GetError() << "\n";
        // Let the OS know shit went sideways when closing this program:
        exit(1);
    }

    this->renderer = SDL_CreateRenderer(this->window, -1, SDL_RENDERER_ACCELERATED);
    if (this->renderer == NULL)
    {
        std::cout << "Failed to create renderer -- Error: " << SDL_GetError() << "\n";
        // Let the OS know shit went sideways when closing this program:
        exit(1);
    }

    int imgsFlags = IMG_INIT_JPG | IMG_INIT_PNG;
    int initted = IMG_Init(imgsFlags);
    if ((initted & imgsFlags) != imgsFlags)
    {
        std::cout << "Couldn't initialize SDL img: " << IMG_GetError() << "\n";
        // Let the OS know shit went sideways when closing this program:

        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        IMG_Quit();
        SDL_Quit();
        exit(1);
    }

    SDL_SetRenderDrawColor(renderer, 120, 144, 156, 255);
    SDL_RenderClear(renderer);
    // Now clear the current rendering target with the drawing color,
    // i.e. since the renderer takes up the entire space of the
    // window, set the entire renderer to a single color.
    // This will NOT be presented on the window, YET.
    // This `clearing of the renderer' is done on the video BACKBUFFER.
    // See the example @ https://wiki.libsdl.org/SDL_RenderClear
}

Screen::~Screen()
{
    startingTick = NULL;
    if (renderer)
    {
        shutdown();
    }
}

void Screen::render()
{
    SDL_RenderPresent(renderer);

    capFrameRate();

    SDL_SetRenderDrawColor(renderer, 120, 144, 156, 255);
    SDL_RenderClear(renderer);
}

void Screen::shutdown()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

SDL_Renderer *Screen::getRenderer()
{
    return renderer;
}

void Screen::capFrameRate()
{
    if ((1000 / FPS) > SDL_GetTicks() - *startingTick) // calulation for checking frame rate if there needs to be waited for the next frame (next load of the textures on the screen)
    {
        SDL_Delay((1000 / FPS) - (SDL_GetTicks() - *startingTick));
    }
}