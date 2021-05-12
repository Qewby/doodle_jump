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

    mQuit = false;
}

Game::~Game() {
    delete mpRenderer;
    delete mpWindow;
    SDL_Quit();
}

void Game::Run() {

    SDL_Rect rect;
    rect.h = 60;
    rect.w = 40;
    rect.x = (mWindowWidth - rect.w) / 2;
    rect.y = mWindowHeight - 200;
    double yAxisSpeed = 10;
    const double yAxisAcceleration = 0.4;
    double xAxisSpeed = 0;
    const double xAxisAcceleration = 0.5;
    const int maxSpeed = 8;

    SDL_Event event;
    const Uint8 *keyboard_state_array = SDL_GetKeyboardState(NULL);

    unsigned int t;
    bool leftPressed = false;
    bool rightPressed = false;
    while(!mQuit)
    {
        t = SDL_GetTicks();
        while(SDL_PollEvent(&event))
        {
            switch (event.type) {
                case SDL_QUIT:
                    mQuit = true;
                    break;
                case SDL_KEYDOWN:
                case SDL_KEYUP:
                    leftPressed = keyboard_state_array[SDL_SCANCODE_LEFT];
                    rightPressed = keyboard_state_array[SDL_SCANCODE_RIGHT];
                    break;
            }
        }

        if (rightPressed && !leftPressed)
        {
            if (xAxisSpeed <= maxSpeed) xAxisSpeed += xAxisAcceleration;
            if (xAxisSpeed < 0) xAxisSpeed = 0;
        }
        else if (!rightPressed && leftPressed)
        {
            if (xAxisSpeed >= -maxSpeed) xAxisSpeed -= xAxisAcceleration;
            if (xAxisSpeed > 0) xAxisSpeed = 0;
        }
        else {
            if (std::abs(xAxisSpeed) < 2) xAxisSpeed = 0;
            else xAxisSpeed /= 1.8;
        }

        rect.x += xAxisSpeed;
        if (rect.x + rect.w / 2 < 0) rect.x += mWindowWidth;
        if (rect.x + rect.w / 2 > mWindowWidth) rect.x -= mWindowWidth;
        rect.y += yAxisSpeed;
        yAxisSpeed += yAxisAcceleration;
        if (rect.y + rect.h > mWindowHeight) yAxisSpeed = -15;

        mpRenderer->ClearScreen();
        SDL_SetRenderDrawColor(mpRenderer->GetRawRenderer(), 255, 255, 255, 255);
        SDL_RenderFillRect(mpRenderer->GetRawRenderer(), &rect);
        mpRenderer->DrawScreen();


        t = SDL_GetTicks () - t;
        if (t < 1000 / mScreenRate) {
            SDL_Delay ((1000 / mScreenRate) - t);
        }
    }


}