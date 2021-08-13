#include "screen.hpp"

Screen::Screen(std::string windowName, int screenWidth, int screenHeight)
{
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
    if (renderer)
    {
        shutdown();
    }
}

void Screen::render()
{
    process_input();

    SDL_RenderPresent(renderer);

    SDL_Delay(16);

    SDL_SetRenderDrawColor(renderer, 120, 144, 156, 255);
    SDL_RenderClear(renderer);
}

void Screen::process_input()
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_QUIT:
            shutdown();
            exit(0);
            break;
        case SDL_KEYDOWN:
            // https://wiki.libsdl.org/CategoryKeyboard
            // https://wiki.libsdl.org/SDL_Scancode
            if (event.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
            {
                shutdown();
                exit(0);
            }
            break;
        default:
            break;
        }
    }
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