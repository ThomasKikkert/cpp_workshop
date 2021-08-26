#include "input.hpp"

Input::Input(Screen *screen, Ball *ball)
{
    this->screen = screen;
    this->ball = ball;
}

void Input::processInput()
{
    bool mouseStateSet = false;

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
            else
            {
                // pass the SDL_KeyboardEvent to a separate handler
                handle_key(DOWN);
            }
            break;

        case SDL_KEYUP:
            // pass the SDL_KeyboardEvent to a separate handler
            handle_key(UP);
            break;

        case SDL_MOUSEBUTTONDOWN:
            handle_mouse(DOWN);
            break;

        default:
            break;
        }
    }

    updatePositions();
}

void Input::handle_key(bool keyState)
{
    if (event.key.repeat == 0)
    {
        if (event.key.keysym.scancode == SDL_SCANCODE_W || event.key.keysym.scancode == SDL_SCANCODE_UP)
        {
            // `keyState' can only take the values 0 (UP) or 1 (DOWN)
            w_upArrow = keyState;
        }
        // Use a separate if-statement for EVERY key, so you can
        // seemingly handle multiple keys pressed at once.
        // NOTE: doing it like this means prioritizing UP (W) over
        // DOWN (S) and LEFT (A) over RIGHT (D) ...
        if (event.key.keysym.scancode == SDL_SCANCODE_S || event.key.keysym.scancode == SDL_SCANCODE_DOWN)
        {
            s_downArrow = keyState;
        }
        if (event.key.keysym.scancode == SDL_SCANCODE_A || event.key.keysym.scancode == SDL_SCANCODE_LEFT)
        {
            a_leftArrow = keyState;
        }
        if (event.key.keysym.scancode == SDL_SCANCODE_D || event.key.keysym.scancode == SDL_SCANCODE_RIGHT)
        {
            d_rightArrow = keyState;
        }
    }
}

void Input::handle_mouse(bool mouseState)
{
    if (event.button.button == SDL_BUTTON_LEFT)
    {
        leftmouseButton = mouseState;
    }
    if (event.button.button == SDL_BUTTON_RIGHT)
    {
        rightmouseButton = mouseState;
    }
}

void Input::updatePositions()
{
    if (w_upArrow)
    {
        ball->updateYSpeed(-yspeed);
        w_upArrow = UP; // set button state to not pressed
    }
    if (s_downArrow)
    {
        ball->updateYSpeed(yspeed);
        s_downArrow = UP; // set button state to not pressed
    }
    if (a_leftArrow)
    {
        ball->updateXSpeed(-xspeed);
        a_leftArrow = UP; // set button state to not pressed
    }
    if (d_rightArrow)
    {
        ball->updateXSpeed(xspeed);
        d_rightArrow = UP; // set button state to not pressed
    }
    if (leftmouseButton)
    {
        ball->moveTowardsMouse();
        leftmouseButton = UP; // set button state to not pressed
    }
    if (rightmouseButton)
    {
        ball->moveAwayFromMouse();
        rightmouseButton = UP; // set button state to not pressed
    }
}

void Input::shutdown()
{
    ball->~Ball();
    screen->~Screen();
}