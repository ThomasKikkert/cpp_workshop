#pragma once

#include <SDL2/SDL.h> // SDL_* functions, enum values and structs
#include "../screen/screen.hpp"
#include "../dvd_logo/dvd_logo.hpp"

class Input
{
private:
    const bool UP = false;
    const bool DOWN = true;

    Dvd_logo *dvd_logo = NULL;
    Screen *screen = NULL;

    SDL_Event event;

    void shutdown();

public:
    Input(Screen *screen, Dvd_logo *dvd_logo);

    void processInput();
};