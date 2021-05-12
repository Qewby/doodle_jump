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
}

Game::~Game() {
    delete mpDoodle;
    delete mpRenderer;
    delete mpWindow;
    SDL_Quit();
}

void Game::Run() {

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
                    leftPressed = keyboard_state_array[SDL_SCANCODE_LEFT] || keyboard_state_array[SDL_SCANCODE_A];
                    rightPressed = keyboard_state_array[SDL_SCANCODE_RIGHT] || keyboard_state_array[SDL_SCANCODE_D];
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

        mpDoodle->GetHitBox().x += xAxisSpeed;
        if (mpDoodle->GetHitBox().x + mpDoodle->GetHitBox().w / 2 < 0) mpDoodle->GetHitBox().x += mWindowWidth;
        if (mpDoodle->GetHitBox().x + mpDoodle->GetHitBox().w / 2 > mWindowWidth) mpDoodle->GetHitBox().x -= mWindowWidth;
        mpDoodle->GetHitBox().y += yAxisSpeed;
        yAxisSpeed += yAxisAcceleration;
        if (mpDoodle->GetHitBox().y + mpDoodle->GetHitBox().h > mWindowHeight) yAxisSpeed = -15;

        mpRenderer->ClearScreen();
        mpDoodle->Draw(*mpRenderer);
        mpRenderer->DrawScreen();


        t = SDL_GetTicks () - t;
        if (t < 1000 / mScreenRate) {
            SDL_Delay ((1000 / mScreenRate) - t);
        }
    }


}