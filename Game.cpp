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
    mScreenRate = displayMode.refresh_rate;

    if (isFullScreen) {
        mpWindow = new Window{name, isFullScreen, mScreenWidth, mScreenHeight};
    } else {
        int height = mScreenHeight * 0.8;
        int width = height / 1.7;
        mpWindow = new Window{name, isFullScreen, width, height};
    }
    SDL_GetWindowSize(mpWindow->GetRawWindow(), &mWindowWidth, &mWindowHeight);

    mpRenderer = new Renderer(*mpWindow);

    mpDoodle = new Doodle(mWindowWidth, mWindowHeight);

    mQuit = false;

    mpHandler = new EventHandler(mQuit);
}

Game::~Game() {
    delete mpDoodle;
    delete mpRenderer;
    delete mpWindow;
    SDL_Quit();
}

void Game::Run() {
    unsigned int t;
    while(!mQuit)
    {
        t = SDL_GetTicks();

        mpHandler->Listen();
        mpDoodle->Move();

        mpRenderer->ClearScreen();
        mpDoodle->Draw(*mpRenderer);
        mpRenderer->DrawScreen();

        t = SDL_GetTicks () - t;
        if (t < 1000 / mScreenRate) {
            SDL_Delay ((1000 / mScreenRate) - t);
        }
    }


}