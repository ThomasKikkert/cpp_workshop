#include "main.hpp"

int main(int argc, char const *argv[])
{
    uint32_t startingTick; // neede for capping frame rate ad 60 fps

    /**
     *  @brief create a screen object with a predefinde screensize 
     *  of SCREEN_WIDTH * SCREEN_HEIGHT
    */
    Screen screen("DVD logo", SCREEN_WIDTH, SCREEN_HEIGHT, &startingTick);
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

    Dvd_logo dvd_logo(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);

	Input input(&screen, &dvd_logo);
    
    while (true)
    {
        startingTick = SDL_GetTicks();

        input.processInput();
        screen.render();

        dvd_logo.render();
    }

    return 0;
}
