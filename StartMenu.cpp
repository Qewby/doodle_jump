#include "StartMenu.h"

StartMenu::StartMenu() {
    const int indent = 20;

    mPlayButtonHitBox.w = mExitButtonHitBox.w = WINDOW_WIDTH / 2;
    mPlayButtonHitBox.h = mExitButtonHitBox.h = mPlayButtonHitBox.w / 2.5;

    mPlayButtonHitBox.x = mExitButtonHitBox.x = (WINDOW_WIDTH - mPlayButtonHitBox.w) / 2;

    mPlayButtonHitBox.y = (WINDOW_HEIGHT - (2 * mPlayButtonHitBox.h + indent)) / 2;
    mExitButtonHitBox.y = mPlayButtonHitBox.y + mPlayButtonHitBox.h + indent;

    mpPlayButtonTexture = nullptr;
    mpOnPlayButtonTexture = nullptr;
    mpExitButtonTexture = nullptr;
    mpOnExitButtonTexture = nullptr;
}

StartMenu::~StartMenu() {
    SDL_DestroyTexture(mpPlayButtonTexture);
    SDL_DestroyTexture(mpOnPlayButtonTexture);
    SDL_DestroyTexture(mpExitButtonTexture);
    SDL_DestroyTexture(mpOnExitButtonTexture);
}
void StartMenu::Draw(Renderer &renderer) {
    if (!mpPlayButtonTexture || !mpOnPlayButtonTexture || !mpExitButtonTexture || !mpOnExitButtonTexture) {
        SDL_Surface *pSurface;
        if (!mpPlayButtonTexture) {
            pSurface = IMG_Load("play.png");
            if (pSurface) {
                mpPlayButtonTexture = SDL_CreateTextureFromSurface(renderer.GetRawRenderer(), pSurface);
                SDL_FreeSurface(pSurface);
            }
        }
        if (!mpOnPlayButtonTexture) {
            pSurface = IMG_Load("play_on.png");
            if (pSurface) {
                mpOnPlayButtonTexture = SDL_CreateTextureFromSurface(renderer.GetRawRenderer(), pSurface);
                SDL_FreeSurface(pSurface);
            }
        }
        if (!mpExitButtonTexture) {
            pSurface = IMG_Load("exit.png");
            if (pSurface) {
                mpExitButtonTexture = SDL_CreateTextureFromSurface(renderer.GetRawRenderer(), pSurface);
                SDL_FreeSurface(pSurface);
            }
        }
        if (!mpOnExitButtonTexture) {
            pSurface = IMG_Load("exit_on.png");
            if (pSurface) {
                mpOnExitButtonTexture = SDL_CreateTextureFromSurface(renderer.GetRawRenderer(), pSurface);
                SDL_FreeSurface(pSurface);
            }
        }
    }

    static SDL_Texture *pPlayTexture = nullptr;
    if (gMousePosition.first - mPlayButtonHitBox.x >= 0 &&
        gMousePosition.first - mPlayButtonHitBox.x <= mPlayButtonHitBox.w &&
        gMousePosition.second - mPlayButtonHitBox.y >= 0 &&
        gMousePosition.second - mPlayButtonHitBox.y <= mPlayButtonHitBox.h) {

        pPlayTexture = mpOnPlayButtonTexture;
    }
    else {
        pPlayTexture = mpPlayButtonTexture;
    }

    static SDL_Texture *pExitTexture = nullptr;
    if (gMousePosition.first - mExitButtonHitBox.x >= 0 &&
            gMousePosition.first - mExitButtonHitBox.x <= mExitButtonHitBox.w &&
            gMousePosition.second - mExitButtonHitBox.y >= 0 &&
            gMousePosition.second - mExitButtonHitBox.y <= mExitButtonHitBox.h) {

        pExitTexture = mpOnExitButtonTexture;
    }
    else {
        pExitTexture = mpExitButtonTexture;
    }

    SDL_RenderCopy(renderer.GetRawRenderer(), pPlayTexture, NULL, &mPlayButtonHitBox);
    SDL_RenderCopy(renderer.GetRawRenderer(), pExitTexture, NULL, &mExitButtonHitBox);
}

StartMenuButton StartMenu::HandleClick() {
    StartMenuButton clickedButton = StartMenuButton::NoneButton;
    if (gLeftMouseClickPosition.first == false) return clickedButton;
    if (gLeftMouseClickPosition.second.first - mPlayButtonHitBox.x >= 0 &&
            gLeftMouseClickPosition.second.first - mPlayButtonHitBox.x <= mPlayButtonHitBox.w &&
            gLeftMouseClickPosition.second.second - mPlayButtonHitBox.y >= 0 &&
            gLeftMouseClickPosition.second.second - mPlayButtonHitBox.y <= mPlayButtonHitBox.h) {

        clickedButton = StartMenuButton::PlayButton;
    }
    if (gLeftMouseClickPosition.second.first - mExitButtonHitBox.x >= 0 &&
            gLeftMouseClickPosition.second.first - mExitButtonHitBox.x <= mExitButtonHitBox.w &&
            gLeftMouseClickPosition.second.second - mExitButtonHitBox.y >= 0 &&
            gLeftMouseClickPosition.second.second - mExitButtonHitBox.y <= mExitButtonHitBox.h) {

        clickedButton = StartMenuButton::ExitButton;
    }
    gLeftMouseClickPosition.first = false;
    SDL_Log("%d", static_cast<int>(clickedButton));
    return clickedButton;
}