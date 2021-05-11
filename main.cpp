#include <iostream>

#include "SDL2/SDL.h"

#include "Window.h"

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main()
{
    bool quit = false;
    SDL_Renderer *renderer;

    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        std::cout << "Can't init SDL: " << SDL_GetError() << std::endl;
        return 1;
    }

    Window window{"Hello world", SCREEN_WIDTH, SCREEN_HEIGHT};

    renderer = SDL_CreateRenderer(window.GetRawWindow(), -1, NULL);
    if (renderer == NULL) {
        std::cout << "Can't create renderer: " << SDL_GetError() << std::endl;
        return 1;
    }

    SDL_Event event;
    while(!quit)
    {
        while(SDL_PollEvent(&event))
        {
            SDL_PumpEvents();
            if(event.type == SDL_QUIT)
                quit=true;
        }
        SDL_RenderClear( renderer );
        SDL_RenderPresent( renderer );
    }

    SDL_DestroyRenderer( renderer );
    SDL_Quit();
    return 0;
}
