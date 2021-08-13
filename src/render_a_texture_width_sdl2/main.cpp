#include "screen/screen.hpp"
#include "texture/texture.hpp"

int main(int argc, char const *argv[])
{

    /**
     *  @brief create a screen object with a predefinde screensize 
     *  of SCREEN_WIDTH * SCREEN_HEIGHT
    */
    Screen screen("hello SDL2 in CPP", SCREEN_WIDTH, SCREEN_HEIGHT);
    SDL_Renderer *renderer = screen.getRenderer();

    /**
    * @brief check if there is a renderer in case the renderer was not created kill
    * shutdown the program
    */
    if (!renderer)
    {
        std::cout << "renderer adres: " << renderer << "\n";
        screen.~Screen();
        exit(1);
    }

    Texture texture(renderer, SCREEN_WIDTH / 2 - 718 / 2, 0, (char *)"gfx/metrix.png");

    while (true)
    {
        screen.render();

        texture.render();
    }

    return 0;
}
