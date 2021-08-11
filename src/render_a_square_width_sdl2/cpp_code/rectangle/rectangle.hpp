/**
 * @file  Rectangle.hpp
 *
 * @brief Headerfile of Rectangle.hpp:
 * handels all the parts for rendering a squar in c++
 * 
 * @author Thomas Kikkert
 **/
#pragma once

#include <SDL2/SDL.h> // SDL_* functions, enum values and structs
#include "../color/color.hpp"

/**
 * @brief give Rectangle the alle the function and variable that the Color class have!
 * 
 **/
class Rectangle : public Color
{
private:
    SDL_Rect rect;
    SDL_Renderer *renderer = NULL;

public:
    /**
    * @brief constuctor for the Rectangle class
    * @param renderer stores the address of the create renderer
    * @param x is the is x positon of the rectangle
    * @param y is the is y positon of the rectangle
    * @param w is the is width of the rectangle
    * @param h is the is height of the rectangle
    * @param hexColorCode stores the hex color code
    * in the folling format RRGGBBAA
    **/
    Rectangle(SDL_Renderer *renderer, int x, int y, int w, int h, std::string hexColorCode);

    /**
    * @brief constuctor for the Rectangle class
    * @param renderer stores the address of the create renderer
    * @param x is the is x positon of the rectangle
    * @param y is the is y positon of the rectangle
    * @param w is the is width of the rectangle
    * @param h is the is height of the rectangle
    * @param R is the Red value is 0 in RGBA
    * @param G is the Green value is 0 in RGBA
    * @param B is the Blue value is 0 in RGBA
    * @param A is the Alpha value is 255 in RGBA, the transparantie
    **/
    Rectangle(SDL_Renderer *renderer, int x, int y, int w, int h, int R, int G, int B, int A);

    /**
    * @brief updates the color of the square
    * @param hexColorCode stores the hex color code
    * in the folling format RRGGBBAA
    **/
    void setColor(std::string hexColorCode);

    /**
    * @brief updates the color of the square
    * @param R is the Red value is 0 in RGBA
    * @param G is the Green value is 0 in RGBA
    * @param B is the Blue value is 0 in RGBA
    * @param A is the Alpha value is 255 in RGBA, the transparantie
    **/
    void setColor(int R, int G, int B, int A);

    void setPosition(int x, int y);

    void changeSize(int w, int h);

    /**
    * @param blendColors whene true the colors are blended 
    * (alphe channels plays a role with the existing layers)
    */
    void render(bool blendColors);
};
