/**
 * @file  color.cpp
 *
 * @author Thomas Kikkert
 */
#include "color.hpp"

Color::Color(int R, int G, int B, int A)
{
    if (R > 255 || R < 0)
    {
        throw "R is not between 0-255";
    }
    if (G > 255 || G < 0)
    {
        throw "G is not between 0-255";
    }
    if (B > 255 || B < 0)
    {
        throw "B is not between 0-255";
    }
    if (A > 255 || A < 0)
    {
        throw "A is not between 0-255";
    }

    this->R = R;
    this->G = G;
    this->B = B;
    this->A = A;
}

Color::Color(std::string hexColorCode)
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
}

Color::Color()
{
    this->R = this->G = this->B = 0;
    this->A = 255;
}

int Color::getR()
{
    return R;
}

int Color::getG()
{
    return G;
}

int Color::getB()
{
    return B;
}

int Color::getA()
{
    return A;
}

void Color::setR(int R)
{
    if (R > 255 || R < 0)
    {
        throw "R is not between 0-255";
    }
    this->R = R;
}

void Color::setG(int G)
{
    if (G > 255 || G < 0)
    {
        throw "G is not between 0-255";
    }
    this->G = G;
}

void Color::setB(int B)
{
    if (B > 255 || B < 0)
    {
        throw "B is not between 0-255";
    }
    this->B = B;
}

void Color::setA(int A)
{
    if (A > 255 || A < 0)
    {
        throw "A is not between 0-255";
    }
    this->A = A;
}