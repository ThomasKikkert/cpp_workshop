#pragma once

#include <vector>
#include <string>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

#include "../texture/texture.hpp"

class Dvd_logo : private Texture
{
    private:
    
    std::vector<std::string> imgPth = {};

    int txtrIndex = 0;
    int screenWidth;
    int screenHeight;
    double xSpeed = 2.0;
    double ySpeed = 2.0;

    float randomSpeedOffset();
    void checkForBorderCollision();
    void updatePosition();
    void setActiveTxtr();
    void loadAnimation();

    public:

    
    Dvd_logo(SDL_Renderer *renderer, int screenWidth, int screenHeight);
    ~Dvd_logo();

    void render();

};