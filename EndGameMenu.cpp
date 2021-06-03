#include "EndGameMenu.h"

EndGameMenu::EndGameMenu() {
    const int indent = 5;
    mScoreLabelHitBox.w = mRecordLabelHitBox.w = WINDOW_WIDTH / 4;
    mScoreLabelHitBox.h = mRecordLabelHitBox.h = mScoreLabelHitBox.w / 2.5;

    mPlayAgainButtonHitBox.w = mMenuButtonHitBox.w = WINDOW_WIDTH / 2;
    mPlayAgainButtonHitBox.h = mMenuButtonHitBox.h = mPlayAgainButtonHitBox.w / 2.5;

    mScoreLabelHitBox.x = mRecordLabelHitBox.x =
            mPlayAgainButtonHitBox.x = mMenuButtonHitBox.x = (WINDOW_WIDTH - mPlayAgainButtonHitBox.w) / 2;

    mScoreLabelHitBox.y = (WINDOW_HEIGHT - (2 * (mPlayAgainButtonHitBox.h + mScoreLabelHitBox.h) +
            3 * indent)) / 2;
    mRecordLabelHitBox.y = mScoreLabelHitBox.y + mScoreLabelHitBox.h + indent;
    mPlayAgainButtonHitBox.y = mRecordLabelHitBox.y + mRecordLabelHitBox.h + indent;
    mMenuButtonHitBox.y = mPlayAgainButtonHitBox.y + mPlayAgainButtonHitBox.h + indent;

    mpPlayAgainButtonTexture = nullptr;
    mpOnPlayAgainButtonTexture = nullptr;
    mpMenuButtonTexture = nullptr;
    mpOnMenuButtonTexture = nullptr;
    mpScoreLabelTexture = nullptr;
    mpRecordLabelTexture = nullptr;
}

EndGameMenu::~EndGameMenu() {

}
void EndGameMenu::Draw(Renderer &renderer) {
    if (!mpPlayAgainButtonTexture || !mpOnPlayAgainButtonTexture || !mpMenuButtonTexture ||
            !mpOnMenuButtonTexture || !mpScoreLabelTexture || !mpRecordLabelTexture) {
        SDL_Surface *pSurface;
        if (!mpPlayAgainButtonTexture) {
            pSurface = IMG_Load("play_again.png");
            if (pSurface) {
                mpPlayAgainButtonTexture = SDL_CreateTextureFromSurface(renderer.GetRawRenderer(), pSurface);
                SDL_FreeSurface(pSurface);
            }
        }
        if (!mpOnPlayAgainButtonTexture) {
            pSurface = IMG_Load("play_again_on.png");
            if (pSurface) {
                mpOnPlayAgainButtonTexture = SDL_CreateTextureFromSurface(renderer.GetRawRenderer(), pSurface);
                SDL_FreeSurface(pSurface);
            }
        }
        if (!mpMenuButtonTexture) {
            pSurface = IMG_Load("menu.png");
            if (pSurface) {
                mpMenuButtonTexture = SDL_CreateTextureFromSurface(renderer.GetRawRenderer(), pSurface);
                SDL_FreeSurface(pSurface);
            }
        }
        if (!mpOnMenuButtonTexture) {
            pSurface = IMG_Load("menu_on.png");
            if (pSurface) {
                mpOnMenuButtonTexture = SDL_CreateTextureFromSurface(renderer.GetRawRenderer(), pSurface);
                SDL_FreeSurface(pSurface);
            }
        }
        if (!mpScoreLabelTexture) {
            pSurface = IMG_Load("score_label.png");
            if (pSurface) {
                mpScoreLabelTexture = SDL_CreateTextureFromSurface(renderer.GetRawRenderer(), pSurface);
                SDL_FreeSurface(pSurface);
            }
        }
        if (!mpRecordLabelTexture) {
            pSurface = IMG_Load("record_label.png");
            if (pSurface) {
                mpRecordLabelTexture = SDL_CreateTextureFromSurface(renderer.GetRawRenderer(), pSurface);
                SDL_FreeSurface(pSurface);
            }
        }
    }

    static SDL_Texture *pPlayAgainTexture = nullptr;
    if (gMousePosition.first - mPlayAgainButtonHitBox.x >= 0 &&
        gMousePosition.first - mPlayAgainButtonHitBox.x <= mPlayAgainButtonHitBox.w &&
        gMousePosition.second - mPlayAgainButtonHitBox.y >= 0 &&
        gMousePosition.second - mPlayAgainButtonHitBox.y <= mPlayAgainButtonHitBox.h) {

        pPlayAgainTexture = mpOnPlayAgainButtonTexture;
    }
    else {
        pPlayAgainTexture = mpPlayAgainButtonTexture;
    }

    static SDL_Texture *pMenuTexture = nullptr;
    if (gMousePosition.first - mMenuButtonHitBox.x >= 0 &&
        gMousePosition.first - mMenuButtonHitBox.x <= mMenuButtonHitBox.w &&
        gMousePosition.second - mMenuButtonHitBox.y >= 0 &&
        gMousePosition.second - mMenuButtonHitBox.y <= mMenuButtonHitBox.h) {

        pMenuTexture = mpOnMenuButtonTexture;
    }
    else {
        pMenuTexture = mpMenuButtonTexture;
    }

    SDL_RenderCopy(renderer.GetRawRenderer(), pPlayAgainTexture, NULL, &mPlayAgainButtonHitBox);
    SDL_RenderCopy(renderer.GetRawRenderer(), pMenuTexture, NULL, &mMenuButtonHitBox);
    SDL_RenderCopy(renderer.GetRawRenderer(), mpScoreLabelTexture, NULL, &mScoreLabelHitBox);
    SDL_RenderCopy(renderer.GetRawRenderer(), mpRecordLabelTexture, NULL, &mRecordLabelHitBox);
}

EndMenuButton EndGameMenu::HandleClick() {
    EndMenuButton clickedButton = EndMenuButton::NoneButton;
    if (gLeftMouseClickPosition.first == false) return clickedButton;
    if (gLeftMouseClickPosition.second.first - mPlayAgainButtonHitBox.x >= 0 &&
        gLeftMouseClickPosition.second.first - mPlayAgainButtonHitBox.x <= mPlayAgainButtonHitBox.w &&
        gLeftMouseClickPosition.second.second - mPlayAgainButtonHitBox.y >= 0 &&
        gLeftMouseClickPosition.second.second - mPlayAgainButtonHitBox.y <= mPlayAgainButtonHitBox.h) {

        clickedButton = EndMenuButton::PlayAgainButton;
    }
    if (gLeftMouseClickPosition.second.first - mMenuButtonHitBox.x >= 0 &&
        gLeftMouseClickPosition.second.first - mMenuButtonHitBox.x <= mMenuButtonHitBox.w &&
        gLeftMouseClickPosition.second.second - mMenuButtonHitBox.y >= 0 &&
        gLeftMouseClickPosition.second.second - mMenuButtonHitBox.y <= mMenuButtonHitBox.h) {

        clickedButton = EndMenuButton::MenuButton;
    }
    gLeftMouseClickPosition.first = false;
    SDL_Log("%d", static_cast<int>(clickedButton));
    return clickedButton;
}