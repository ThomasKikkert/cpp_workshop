/**
 * @file  color.hpp
 *
 * @brief Headerfile of color.hpp:
 * stores the data RGBA values 0-255
 * and associated function
 * 
 * @author Thomas Kikkert
 **/
#pragma once

#include <string>
#include <iostream>
#include <stdlib.h>

/**
* @brief color class for stroring the RGBA values
* */
class Color
{
protected:
    int R;
    int G;
    int B;
    int A;

public:
    /**
    * @brief default constructor for the color class
    * @param R is the Red value is 0 in RGBA
    * @param G is the Green value is 0 in RGBA
    * @param B is the Blue value is 0 in RGBA
    * @param A is the Alpha value is 255 in RGBA, the transparantie
    **/
    Color();

    /**
    * @brief constructor for the color class
    * @param R is the Red value 0-255 in RGBA
    * @param G is the Green value 0-255 in RGBA
    * @param B is the Blue value 0-255 in RGBA
    * @param A is the Alpha value 0-255 in RGBA, the transparantie
    **/
    Color(int R, int G, int B, int A);

    /**
    * @brief constructor for the color class.
    * the hex code will be translate into the corespondig RGBA values
    * 
    * @param hexColorCode the hex format is as following RRGGBBAA example blue is #FF0000FF.
    **/
    Color(std::string hexColorCode);

    /**
    * @brief returns the intensity of the Red value
    * @return value between 0 and 255
    **/
    int getR();

    /**
    * @brief returns the intensity of the Green value
    * @return value between 0 and 255
    **/
    int getG();

    /**
    * @brief returns the intensity of the Blue value
    * @return value between 0 and 255
    **/
    int getB();

    /**
    * @brief returns the intensity of the Alpha value
    * @return value between 0 and 255
    **/
    int getA();

    /**
    * @brief updates the set R value to the new value of R
    * @param R set the Red value between 0 and 255
    **/
    void setR(int R);

    /**
    * @brief updates the set G value to the new value of G
    * @param G set the Green value between 0 and 255
    **/
    void setG(int G);

    /**
    * @brief updates the set B value to the new value of B
    * @param B set the Blue value between 0 and 255
    **/
    void setB(int B);

    /**
    * @brief updates the set R value to the new value of A
    * @param A set the Alpha value between 0 and 255
    **/
    void setA(int A);
};