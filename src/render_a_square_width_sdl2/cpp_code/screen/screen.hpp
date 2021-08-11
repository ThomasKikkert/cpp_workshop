#pragma once

#include <iostream>
#include <string>
#include <SDL2/SDL.h> // SDL_* functions, enum values and structs

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720

class Screen
{
private:
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;

    void process_input();

    

public:
    Screen(std::string windowName, int screenWidth, int screenHeight);
    ~Screen();
    
    void render();

    void shutdown();

    SDL_Renderer *getRenderer();
};
