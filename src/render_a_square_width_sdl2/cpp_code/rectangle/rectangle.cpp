#include "rectangle.hpp"

Rectangle::Rectangle(SDL_Renderer *renderer, int x, int y, int w, int h, std::string hexColorCode)
{
    this->renderer = renderer;
    rect.x = x;
    rect.y = y;
    rect.w = w;
    rect.h = h;
    setColor(hexColorCode);
}

Rectangle::Rectangle(SDL_Renderer *renderer, int x, int y, int w, int h, int R, int G, int B, int A)
{
    this->renderer = renderer;
    rect.x = x;
    rect.y = y;
    rect.w = w;
    rect.h = h;
    this->R = R;
    this->G = G;
    this->B = B;
    this->A = A;
}

void Rectangle::setColor(std::string hexColorCode)
{
    if (8 > hexColorCode.size() || hexColorCode.size() > 9)
    {
        throw("does not meet the format requirements of RRGGBBAA or #RRGGBBAA");
    }
    if (hexColorCode.front() == '#')
    {
        hexColorCode.erase(hexColorCode.begin());
    }
    std::string hex = hexColorCode.substr(0, 2);
    this->R = stoi(hex, 0, 16);

    hex = hexColorCode.substr(2, 2);
    this->G = stoi(hex, 0, 16);

    hex = hexColorCode.substr(4, 2);
    this->B = stoi(hex, 0, 16);

    hex = hexColorCode.substr(6, 2);
    this->A = stoi(hex, 0, 16);

    //std::cout << "R value: " << R;
    //std::cout << ", G value: " << G;
    //std::cout << ", B value: " << B;
    //std::cout << ", A value: " << A << "\n";
}

void Rectangle::setColor(int R, int G, int B, int A)
{
    this->R = R;
    this->G = G;
    this->B = B;
    this->A = A;
}

void Rectangle::setPosition(int x, int y)
{
    rect.x = x;
    rect.y = y;
}

void Rectangle::changeSize(int w, int h)
{
    rect.w = w;
    rect.h = h;
}

void Rectangle::render(bool blendColors)
{
    SDL_SetRenderDrawColor(renderer, R, G, B, A);

    if (blendColors)
    {
        SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
    }

    SDL_RenderFillRect(renderer, &rect);

    if (blendColors)
    {
        SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_NONE);        
    }
}