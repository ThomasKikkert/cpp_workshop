#include "screen/screen.hpp"

int main(int argc, char const *argv[])
{

    /**
     *  @brief create a screen object with a predefinde screensize 
     *  of SCREEN_WIDTH * SCREEN_HEIGHT
    */
    Screen screen("hello SDL2 in CPP", SCREEN_WIDTH, SCREEN_HEIGHT);

    while(true)
    {
        screen.render(); 
    }

    return 0;
}
