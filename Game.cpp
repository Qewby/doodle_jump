#include "Game.h"

const int gcMaxScoreLength = 10;
unsigned long long SCORE = 0;
unsigned long long  RECORD = 0;

int WINDOW_HEIGHT;
int WINDOW_WIDTH;

Game::Game(std::string name, bool isFullScreen) : mListener(mQuit) {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        std::cerr << "Can't init SDL: " << SDL_GetError() << std::endl;
        throw std::bad_alloc();
    }
    if (TTF_Init() != 0) {
        std::cerr << "Can't init TTF: " << TTF_GetError() << std::endl;
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
        int height = mScreenHeight * 0.9;
        int width = height / 1.7;
        mpWindow = new Window{name, isFullScreen, width, height};
    }
    SDL_GetWindowSize(mpWindow->GetRawWindow(), &mWindowWidth, &mWindowHeight);
    WINDOW_HEIGHT = mWindowHeight;
    WINDOW_WIDTH = mWindowWidth;

    mpRenderer = new Renderer(*mpWindow);

    mpField = new Field(mQuit);

    mpDoodle = new Doodle(*mpField);

    mpCollisionHandler = new CollisionHandler(*mpField, *mpDoodle);

    mQuit = false;
}

Game::~Game() {
    delete mpCollisionHandler;
    delete mpDoodle;
    delete mpField;
    delete mpRenderer;
    delete mpWindow;
    TTF_Quit();
    SDL_Quit();
}

void Game::Run() {

    EndGameMenu menu{};

    ScoreLine line{};

    unsigned int t;
    while(!mQuit)
    {
        t = SDL_GetTicks();

        mListener.Listen();
        mpDoodle->Move();
        mpCollisionHandler->Handle();

        mpRenderer->ClearScreen();
        mpField->Draw(*mpRenderer);
        mpDoodle->Draw(*mpRenderer);
        line.Draw(*mpRenderer);
        menu.Draw(*mpRenderer);
        mpRenderer->DrawScreen();

        menu.HandleClick();

        t = SDL_GetTicks () - t;
        if (t < 1000 / mScreenRate) {
            SDL_Delay ((1000 / mScreenRate) - t);
        }
    }
}