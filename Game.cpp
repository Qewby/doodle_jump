#include "Game.h"

int SCORE = 0;

int WINDOW_HEIGHT;
int WINDOW_WIDTH;

Game::Game(std::string name, bool isFullScreen) : mListener(mQuit) {
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
        int height = mScreenHeight * 0.9;
        int width = height / 1.7;
        mpWindow = new Window{name, isFullScreen, width, height};
    }
    SDL_GetWindowSize(mpWindow->GetRawWindow(), &mWindowWidth, &mWindowHeight);
    WINDOW_HEIGHT = mWindowHeight;
    WINDOW_WIDTH = mWindowWidth;

    mpRenderer = new Renderer(*mpWindow);

    mpField = new Field();

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
    SDL_Quit();
}

void Game::Run() {

    TTF_Init();
    TTF_Font *font = TTF_OpenFont("arial.ttf", 25);
    SDL_Color color = { 255,0 ,0 };
    SDL_Surface *surface;
    SDL_Texture *texture;
    SDL_Rect textHitBox;
    textHitBox.h = 30;
    textHitBox.w = 60;
    textHitBox.x = 0;
    textHitBox.y = 0;

    unsigned int t;
    while(!mQuit)
    {
        t = SDL_GetTicks();

        surface = TTF_RenderText_Solid(font,std::to_string(SCORE).c_str(), color);
        texture = SDL_CreateTextureFromSurface(mpRenderer->GetRawRenderer(), surface);

        mListener.Listen();
        mpDoodle->Move();
        mpCollisionHandler->Handle();

        mpRenderer->ClearScreen();
        mpField->Draw(*mpRenderer);
        mpDoodle->Draw(*mpRenderer);
        SDL_RenderCopy(mpRenderer->GetRawRenderer(), texture, NULL, &textHitBox);
        mpRenderer->DrawScreen();

        t = SDL_GetTicks () - t;
        if (t < 1000 / mScreenRate) {
            SDL_Delay ((1000 / mScreenRate) - t);
        }
    }

    SDL_DestroyTexture(texture);
    SDL_FreeSurface(surface);
    TTF_CloseFont(font);
    TTF_Quit();
}