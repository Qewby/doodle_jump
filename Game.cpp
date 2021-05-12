#include "Game.h"

Game::Game(std::string name, bool isFullScreen) {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        std::cerr << "Can't init SDL: " << SDL_GetError() << std::endl;
        throw std::bad_alloc();
    }

    SDL_DisplayMode displayMode;
    SDL_GetCurrentDisplayMode(0, &displayMode);
    mScreenWidth = displayMode.w;
    mScreenHeight = displayMode.h;

    if (isFullScreen) {
        mpWindow = new Window{name, isFullScreen, mScreenWidth, mScreenHeight};
    } else {
        int height = mScreenHeight * 0.8;
        int width = height / 1.7;
        mpWindow = new Window{name, isFullScreen, width, height};
    }
    SDL_GetWindowSize(mpWindow->GetRawWindow(), &mWindowWidth, &mWindowHeight);
    mQuit = false;
}

Game::~Game() {
    delete mpWindow;
    SDL_Quit();
}

void Game::Run() {
    SDL_Renderer *renderer;

    renderer = SDL_CreateRenderer(mpWindow->GetRawWindow(), -1, NULL);
    if (renderer == NULL) {
        std::cerr << "Can't create renderer: " << SDL_GetError() << std::endl;
        throw std::bad_alloc();
    }

    SDL_Rect rect;
    rect.x = 20;
    rect.y = 20;
    rect.h = 30;
    rect.w = 30;

    SDL_Event event;
    const Uint8 *keyboard_state_array = SDL_GetKeyboardState(NULL);
    while(!mQuit)
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
                mQuit = true;
            }
        }
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderFillRect(renderer, &rect);
        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
}