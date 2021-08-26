#include "ball.hpp"

Ball::Ball(SDL_Renderer *renderer, int xPos, int yPos, std::string imgPth, int screenWidth, int screenHeight)
{
    this->renderer = renderer;
    this->x = xPos;
    this->y = yPos;
    load_texture((char *)imgPth.c_str());
    this->screenWidth = screenWidth;
    this->screenHeight = screenHeight;
}

Ball::~Ball()
{
    renderer = NULL;
    if (txtr)
    {
        SDL_DestroyTexture(txtr);
        txtr = NULL;
    }
}

void Ball::render()
{
    SDL_Rect dest;

    applyGravity();
    applyAcceleration();
    checkForBorderCollision();

    dest.x = x;
    dest.y = y;

    SDL_QueryTexture(txtr, NULL, NULL, &dest.w, &dest.h);
    SDL_RenderCopy(renderer, txtr, NULL, &dest);
}

void Ball::checkForBorderCollision()
{
    if (x < 0)
    {
        x = 0;
        xAcceleration = -xAcceleration * 0.65f;
        xSpeed = -xSpeed * 0.65f;
    }
    else if (x > screenWidth - 99)
    {
        x = screenWidth - 99;
        xAcceleration = -xAcceleration * 0.65f;
        xSpeed = -xSpeed * 0.65f;
    }

    if (y < 0)
    {
        y = 0;
        yAcceleration = -yAcceleration * 0.65f;
        ySpeed = -ySpeed * 0.65f;
    }
    else if (y > screenHeight - 96)
    {
        y = screenHeight - 96;
        yAcceleration = -yAcceleration * 0.65f;
        ySpeed = -ySpeed * 0.65f;
    }
}

void Ball::applyGravity()
{
    yAcceleration += 0.075f;
}

void Ball::applyAcceleration()
{
    xSpeed += xAcceleration;
    x += (int)xSpeed;
    ySpeed += yAcceleration;
    y += (int)ySpeed;
}

void Ball::moveTowardsMouse()
{
    int mouse_x;
    int mouse_y;
    SDL_GetMouseState(&mouse_x, &mouse_y);
    int delta_x = delta(mouse_x, x);
    int delta_y = delta(mouse_y, y);

    double mag = sqrt(delta_x * delta_x + delta_y * delta_y);
    if (mag == 0)
    {
        return; // prevents div by 0
    }

    double normalizedXAcceleration;
    double normalizedYAcceleration;

    // the accelertion towards the mouse is slower when it is closer to the mouse
    if (mag > 0 && mag < 250)
    {
        normalizedXAcceleration = ((delta_x * 0.15) / mag);
        normalizedYAcceleration = ((delta_y * 0.15) / mag);
    }
    else if (mag >= 250 && mag < 350)
    {
        normalizedXAcceleration = ((delta_x * 0.35) / mag);
        normalizedYAcceleration = ((delta_y * 0.35) / mag);
    }
    else if (mag >= 350 && mag < 500)
    {
        normalizedXAcceleration = ((delta_x * 0.65) / mag);
        normalizedYAcceleration = ((delta_y * 0.65) / mag);
    }
    else
    {
        normalizedXAcceleration = ((delta_x * 0.85) / mag);
        normalizedYAcceleration = ((delta_y * 0.85) / mag);
    }

    xAcceleration += normalizedXAcceleration;
    yAcceleration += normalizedYAcceleration;
}

void Ball::moveAwayFromMouse()
{
    int mouse_x;
    int mouse_y;
    SDL_GetMouseState(&mouse_x, &mouse_y);
    int delta_x = delta(mouse_x, x);
    int delta_y = delta(mouse_y, y);

    double mag = sqrt(delta_x * delta_x + delta_y * delta_y);
    if (mag == 0)
    {
        return; // prevents div by 0
    }

    double normalizedXAcceleration;
    double normalizedYAcceleration;

    // the accelertion towards the mouse is slower when it is closer to the mouse
    if (mag > 0 && mag < 250)
    {
        normalizedXAcceleration = -((delta_x * 0.85) / mag);
        normalizedYAcceleration = -((delta_y * 0.85) / mag);
    }
    else if (mag >= 250 && mag < 350)
    {
        normalizedXAcceleration = -((delta_x * 0.65) / mag);
        normalizedYAcceleration = -((delta_y * 0.65) / mag);
    }
    else if (mag >= 350 && mag < 500)
    {
        normalizedXAcceleration = -((delta_x * 0.85) / mag);
        normalizedYAcceleration = -((delta_y * 0.85) / mag);
    }
    else
    {
        normalizedXAcceleration = -((delta_x * 0.15) / mag);
        normalizedYAcceleration = -((delta_y * 0.15) / mag);
    }

    xAcceleration += normalizedXAcceleration;
    yAcceleration += normalizedYAcceleration;
}

int Ball::delta(int a, int b)
{
    return a - b;
}

void Ball::updateXSpeed(double xspeed)
{
    this->xSpeed += xspeed;
}

void Ball::updateYSpeed(double yspeed)
{
    this->ySpeed += yspeed;
}
