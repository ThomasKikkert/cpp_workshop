#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <SDL2/SDL.h> // SDL_* functions, enum values and structs

#define SCREEN_WIDTH (int)1280
#define SCREEN_HEIGHT (int)720

void process_input(void);
void proper_shutdown(void);


#endif // end of MAIN_H