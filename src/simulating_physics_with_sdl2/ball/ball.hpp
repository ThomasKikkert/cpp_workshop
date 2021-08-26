#pragma once

#include <math.h>
#include "../texture/texture.hpp"

class Ball : private Texture // the private for Texture makes alle data in side the Texture to be invisable form the outside but not for the inside!!
{
private:
    int screenWidth;
    int screenHeight;

    double xSpeed = 0;
    double ySpeed = 0;
    double xAcceleration = 0;
    double yAcceleration = 0;

    void checkForBorderCollision();
    void applyGravity();
    void applyAcceleration();
    
    int delta(int a, int b);

public:

    Ball(SDL_Renderer *renderer, int xPos, int yPos, std::string imgPth, int screenWidth, int screenHeight);
    ~Ball();
    
    void updateXSpeed(double xspeed);
    void updateYSpeed(double yspeed);
    void moveTowardsMouse();
    void moveAwayFromMouse();
    void render();
};