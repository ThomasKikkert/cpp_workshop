#pragma once

#include <SDL2/SDL.h> // SDL_* functions, enum values and structs
#include "../screen/screen.hpp"
#include "../ball/ball.hpp"

class Input
{
private:
    const bool UP = false;
    const bool DOWN = true;

    Ball *ball = NULL;
    Screen *screen = NULL;

    SDL_Event event;

    bool leftmouseButton = false;  // when true the ball moves toward mous position
    bool rightmouseButton = false; // when true the ball moves away form the mouse position
    bool w_upArrow = false;        // when true the ball moves towards the top of the screen
    bool s_downArrow = false;      // when true the ball moves towards the bottom of the screen
    bool a_leftArrow = false;      // when true the ball moves towards the left side of the screen
    bool d_rightArrow = false;     // when true the ball moves towards the right side of the screen
    const float xspeed = 2.7f;     // x speed used for updating the balls position
    const float yspeed = 2.7f;     // x speed used for updating the balls position

    void shutdown();
    void handle_key(bool keyState);     // handels al most of the keypressed that don't need to be handeled fast
    void handle_mouse(bool mouseState); // checks is left mouse butten is pressed
    void updatePositions();

public:
    Input(Screen *screen, Ball *ball);

    void processInput();
};