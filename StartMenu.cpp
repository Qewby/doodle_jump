#include "StartMenu.h"

StartMenu::StartMenu() {
    const int indent = 20;

    mStartButtonHitBox.w = mExitButtonHitBox.w = WINDOW_WIDTH / 2;
    mStartButtonHitBox.h = mExitButtonHitBox.h = mStartButtonHitBox.w / 2.5;

    mStartButtonHitBox.x = mExitButtonHitBox.x = (WINDOW_WIDTH - mStartButtonHitBox.w) / 2;

    mStartButtonHitBox.y = (WINDOW_HEIGHT - (2 * mStartButtonHitBox.h + indent)) / 2;
    mExitButtonHitBox.y = mStartButtonHitBox.y + mStartButtonHitBox.h + indent;

    mpStartButtonTexture = nullptr;
    mpOnStartButtonTexture = nullptr;
    mpExitButtonTexture = nullptr;
    mpOnExitButtonTexture = nullptr;
}

StartMenu::~StartMenu() {

}
void StartMenu::Draw(Renderer &renderer) {
    if (!mpStartButtonTexture || !mpOnStartButtonTexture || !mpExitButtonTexture || !mpOnExitButtonTexture) {
        SDL_Surface *pSurface;
        if (!mpStartButtonTexture) {
            pSurface = IMG_Load("play.png");
            if (pSurface) {
                mpStartButtonTexture = SDL_CreateTextureFromSurface(renderer.GetRawRenderer(), pSurface);
                SDL_FreeSurface(pSurface);
            }
        }
        if (!mpOnStartButtonTexture) {
            pSurface = IMG_Load("play_on.png");
            if (pSurface) {
                mpOnStartButtonTexture = SDL_CreateTextureFromSurface(renderer.GetRawRenderer(), pSurface);
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

    static SDL_Texture *pStartTexture = nullptr;
    if (gMousePosition.first - mStartButtonHitBox.x >= 0 &&
            gMousePosition.first - mStartButtonHitBox.x <= mStartButtonHitBox.w &&
            gMousePosition.second - mStartButtonHitBox.y >= 0 &&
            gMousePosition.second - mStartButtonHitBox.y <= mStartButtonHitBox.h) {

        pStartTexture = mpOnStartButtonTexture;
    }
    else {
        pStartTexture = mpStartButtonTexture;
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

    SDL_RenderCopy(renderer.GetRawRenderer(), pStartTexture, NULL, &mStartButtonHitBox);
    SDL_RenderCopy(renderer.GetRawRenderer(), pExitTexture, NULL, &mExitButtonHitBox);
}