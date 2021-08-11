#include "screen/screen.hpp"
#include "rectangle/rectangle.hpp"

int main(int argc, char const *argv[])
{

    /**
     *  @brief create a screen object with a predefinde screensize 
     *  of SCREEN_WIDTH * SCREEN_HEIGHT
    */
    Screen screen("hello SDL2 in CPP", SCREEN_WIDTH, SCREEN_HEIGHT);
    SDL_Renderer *renderer = screen.getRenderer();

    int rectSize = 90;
    Rectangle rect(renderer, SCREEN_WIDTH / 2 - rectSize, SCREEN_HEIGHT / 2 - rectSize, rectSize, rectSize, "FF000032");
    Rectangle rect1(renderer, SCREEN_WIDTH / 2 - rectSize, SCREEN_HEIGHT / 2 + rectSize/2, rectSize, rectSize, "FF000032");

    while (true)
    {
        screen.render();

        rect.render(false);
        rect1.render(true);
        
    }

    return 0;
}
