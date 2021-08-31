#pragma once

#include <iostream>
#include <string>
#include <SDL2/SDL.h> // SDL_* functions, enum values and structs
#include <SDL2/SDL_image.h>

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720

class Screen
{
private:
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;
    SDL_Event event;
    const int FPS = 60;
    uint32_t *startingTick;

    void process_input();
    void capFrameRate();

public:
    Screen(std::string windowName, int screenWidth, int screenHeight, uint32_t *startingTick);
    ~Screen();
    
    void render();

    void shutdown();

    SDL_Renderer *getRenderer();
};
