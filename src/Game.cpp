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

    mpField = new Field(mLose, *mpRenderer);
    mpDoodle = new Doodle(*mpField, *mpRenderer);
    mpCollisionHandler = new CollisionHandler(*mpField, *mpDoodle);

    mpScoreLine = new ScoreLine(*mpRenderer);
    mpStartMenu = new StartMenu(*mpRenderer);
    mpEndMenu = new EndGameMenu(*mpRenderer);
    mpTypeMenu = new TypeNameMenu(*mpRenderer);

    mpRecordTable = new RecordTable(*mpRenderer);
    mpRecordTable->ReadTable();

    mLose = false;
    mQuit = false;
}

Game::~Game() {
    delete mpRecordTable;
    delete mpTypeMenu;
    delete mpEndMenu;
    delete mpStartMenu;
    delete mpScoreLine;
    delete mpCollisionHandler;
    delete mpDoodle;
    delete mpField;
    delete mpRenderer;
    delete mpWindow;
    TTF_Quit();
    SDL_Quit();
}

void Game::Run() {

    unsigned int t;
    while(!mQuit)
    {
        t = SDL_GetTicks();
        mpRenderer->ClearScreen();

        mListener.Listen();
        mpField->Draw();
        if (mLose) {
            mpEndMenu->Draw();
            switch (mpEndMenu->HandleClick()) {
                case EndMenuButton::MenuButton:
                    mLose = false;
                    break;
                case EndMenuButton::PlayAgainButton:
                    mLose = false;
                    Play();
                    break;
            }
        }
        else {
            mpStartMenu->Draw();
            switch (mpStartMenu->HandleClick()) {
                case StartMenuButton::ExitButton:
                    mQuit = true;
                    break;
                case StartMenuButton::RecordsButton:
                    WatchRecordTable();
                    break;
                case StartMenuButton::PlayButton:
                    Play();
                    break;
            }
        }

        mListener.Listen();
        mpRenderer->DrawScreen();
        t = SDL_GetTicks () - t;
        if (t < 1000 / mScreenRate) {
            SDL_Delay ((1000 / mScreenRate) - t);
        }
    }
}

void Game::Play() {
    SCORE = 0;
    mpField->Refill();
    mpDoodle->Respawn();

    unsigned int t;
    while (!mLose && !mQuit) {
        t = SDL_GetTicks();
        mpRenderer->ClearScreen();

        mListener.Listen();
        mpField->Draw();
        mpDoodle->Draw();
        mpScoreLine->Draw();
        mpDoodle->Move();
        mpCollisionHandler->Handle();
        mListener.Listen();

        mpRenderer->DrawScreen();
        t = SDL_GetTicks () - t;
        if (t < 1000 / mScreenRate) {
            SDL_Delay ((1000 / mScreenRate) - t);
        }
    }

    mpField->Clear();
    UpdateRecord();
    mpEndMenu->Update();
}

void Game::UpdateRecord() {
    SDL_StartTextInput();
    mpTypeMenu->Reset();
    if (mpRecordTable->IsRecord()) {
        unsigned int t;
        while (!mpTypeMenu->HandleActions() && !mQuit) {
            t = SDL_GetTicks();
            mpRenderer->ClearScreen();

            mListener.Listen();
            mpField->Draw();
            mpTypeMenu->Draw();

            mpRenderer->DrawScreen();
            t = SDL_GetTicks () - t;
            if (t < 1000 / mScreenRate) {
                SDL_Delay ((1000 / mScreenRate) - t);
            }
        }
        mpRecordTable->UpdateTable(mpTypeMenu->GetName());
    }
    SDL_StopTextInput();
}

void Game::WatchRecordTable() {
    unsigned int t;
    while (!mpRecordTable->HandleClick() && !mQuit) {
        t = SDL_GetTicks();
        mpRenderer->ClearScreen();

        mListener.Listen();
        mpField->Draw();
        mpRecordTable->Draw();

        mpRenderer->DrawScreen();
        t = SDL_GetTicks () - t;
        if (t < 1000 / mScreenRate) {
            SDL_Delay ((1000 / mScreenRate) - t);
        }
    }
}
