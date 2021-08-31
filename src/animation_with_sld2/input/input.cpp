#include "input.hpp"

Input::Input(Screen *screen, Dvd_logo *dvd_logo)
{
    this->screen = screen;
    this->dvd_logo = dvd_logo;
}

void Input::processInput()
{
    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_QUIT:
            shutdown();
            exit(0);
        case SDL_KEYDOWN:
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

void Input::shutdown()
{
    dvd_logo->~Dvd_logo();
    screen->~Screen();
}