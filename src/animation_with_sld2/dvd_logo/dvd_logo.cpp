#include "dvd_logo.hpp"

Dvd_logo::Dvd_logo(SDL_Renderer *renderer, int screenWidth, int screenHeight)
{
    x = screenWidth / 2;
    y = screenHeight / 2;

    srand(time(NULL)); // random seed for random num generator
    txtrIndex = rand() % 7;

    width = 199;
    height = 109;

    this->screenWidth = screenWidth;
    this->screenHeight = screenHeight;
    this->renderer = renderer;

    loadAnimation();
}

Dvd_logo::~Dvd_logo()
{
    this->~Texture();
}

void Dvd_logo::loadAnimation()
{
    imgPth.push_back("gfx/dvd_logo_white.png");
    imgPth.push_back("gfx/dvd_logo_red.png");
    imgPth.push_back("gfx/dvd_logo_blue.png");
    imgPth.push_back("gfx/dvd_logo_green.png");
    imgPth.push_back("gfx/dvd_logo_orange.png");
    imgPth.push_back("gfx/dvd_logo_purple.png");
    imgPth.push_back("gfx/dvd_logo_yellow.png");

    load_texture((char *)imgPth[txtrIndex].c_str());
}

void Dvd_logo::checkForBorderCollision()
{
    bool changeTexture = false;

    if (x < 0)
    {
        x = 0;
        xSpeed = -xSpeed + randomSpeedOffset();
        changeTexture = true;
    }
    else if (x > screenWidth - width)
    {
        x = screenWidth - width;
        xSpeed = -xSpeed + randomSpeedOffset();
        changeTexture = true;
    }

    if (y < 0)
    {
        y = 0;
        ySpeed = -ySpeed + randomSpeedOffset();
        changeTexture = true;
    }
    else if (y > screenHeight - height)
    {
        y = screenHeight - height;
        ySpeed = -ySpeed + randomSpeedOffset();
        changeTexture = true;
    }

    if (changeTexture)
    {
        setActiveTxtr();
    }
}

void Dvd_logo::updatePosition()
{
    if (!(3 > xSpeed && xSpeed > 1) && !(xSpeed > -3 && -1 > xSpeed))
    {
        if (xSpeed > 0)
        {
            xSpeed = 2.0f;
        }
        else
        {
            xSpeed = -2.0f;
        }
    }
    if (!(3 > ySpeed && ySpeed > 1) && !(ySpeed > -3 && -1 > ySpeed))
    {
        if (ySpeed > 0)
        {
            ySpeed = 2.0f;
        }
        else
        {
            ySpeed = -2.0f;
        }
    }

    x += (int)xSpeed;
    y += (int)ySpeed;
}

void Dvd_logo::setActiveTxtr()
{
    if (txtrIndex >= 7)
    {
        txtrIndex = 0;
    }

    load_texture((char *)imgPth[txtrIndex].c_str());
    txtrIndex++;
}

void Dvd_logo::render()
{

    SDL_Rect dest;
    updatePosition();
    checkForBorderCollision();

    dest.x = x;
    dest.y = y;

    SDL_QueryTexture(txtr, NULL, NULL, &dest.w, &dest.h);
    SDL_RenderCopy(renderer, txtr, NULL, &dest);
}

float Dvd_logo::randomSpeedOffset()
{
    int value = rand() % 5;

    switch (value)
    {
    case 0:
        return -0.3f;
        break;

    case 1:
        return -0.1f;
        break;

    case 2:
        return 0.0f;
        break;

    case 3:
        return 0.1f;
        break;

    case 4:
        return 0.3f;
        break;

    default:
        break;
    }
    return 0.0f;
}