#include <iostream>

#include "SDL2/SDL.h"

#include "Window.h"

const int SCREEN_WIDTH = 480;
const int SCREEN_HEIGHT = 760;

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

    SDL_Rect rect;
    rect.x = 20;
    rect.y = 20;
    rect.h = 30;
    rect.w = 30;

    SDL_Event event;
    const Uint8 *keyboard_state_array = SDL_GetKeyboardState(NULL);
    while(!quit)
    {
        while(SDL_PollEvent(&event))
        {
            SDL_PumpEvents();
            if(event.type == SDL_KEYDOWN || event.type == SDL_KEYUP)
            {
                if (keyboard_state_array[SDL_SCANCODE_UP] && !(keyboard_state_array[SDL_SCANCODE_DOWN]))
                {
                    rect.y -= 5;
                }
                else if (!keyboard_state_array[SDL_SCANCODE_UP] && keyboard_state_array[SDL_SCANCODE_DOWN])
                {
                    rect.y += 5;
                }

                if (keyboard_state_array[SDL_SCANCODE_RIGHT] && !keyboard_state_array[SDL_SCANCODE_LEFT])
                {
                    rect.x += 5;
                }
                else if (!keyboard_state_array[SDL_SCANCODE_RIGHT] && keyboard_state_array[SDL_SCANCODE_LEFT])
                {
                    rect.x -= 5;
                }
            }
            if (event.type == SDL_QUIT) {
                quit = true;
            }
        }
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderFillRect(renderer, &rect);
        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    return 0;
}
