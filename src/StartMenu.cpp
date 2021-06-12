#include "StartMenu.h"

StartMenu::StartMenu(Renderer& renderer) : Drawable(renderer) {
    const int indent = 20;

    mPlayButtonHitBox.w = mExitButtonHitBox.w = mRecordsButtonHitBox.w = WINDOW_WIDTH / 2;
    mPlayButtonHitBox.h = mExitButtonHitBox.h = mRecordsButtonHitBox.h = mPlayButtonHitBox.w / 2.5;

    mPlayButtonHitBox.x = mExitButtonHitBox.x = mRecordsButtonHitBox.x = (WINDOW_WIDTH - mPlayButtonHitBox.w) / 2;

    mPlayButtonHitBox.y = (WINDOW_HEIGHT - (3 * mPlayButtonHitBox.h + 2 * indent)) / 2;
    mRecordsButtonHitBox.y = mPlayButtonHitBox.y + mPlayButtonHitBox.h + indent;
    mExitButtonHitBox.y = mRecordsButtonHitBox.y + mRecordsButtonHitBox.h + indent;

    mpPlayButtonTexture = nullptr;
    mpOnPlayButtonTexture = nullptr;
    mpExitButtonTexture = nullptr;
    mpOnExitButtonTexture = nullptr;
    mpRecordsButtonTexture = nullptr;
    mpOnRecordsButtonTexture = nullptr;

    SDL_Surface *pSurface;
    std::string path;

    path = "assets/textures/play.png";
    pSurface = IMG_Load(path.c_str());
    if (pSurface) {
        mpPlayButtonTexture = SDL_CreateTextureFromSurface(mrRenderer.GetRawRenderer(), pSurface);
        SDL_FreeSurface(pSurface);
    }
    else {
        SDL_Log("ERROR: can't load texture: %s", path.c_str());
    }

    path = "assets/textures/play_on.png";
    pSurface = IMG_Load(path.c_str());
    if (pSurface) {
        mpOnPlayButtonTexture = SDL_CreateTextureFromSurface(mrRenderer.GetRawRenderer(), pSurface);
        SDL_FreeSurface(pSurface);
    }
    else {
        SDL_Log("ERROR: can't load texture: %s", path.c_str());
    }

    path = "assets/textures/exit.png";
    pSurface = IMG_Load(path.c_str());
    if (pSurface) {
        mpExitButtonTexture = SDL_CreateTextureFromSurface(mrRenderer.GetRawRenderer(), pSurface);
        SDL_FreeSurface(pSurface);
    }
    else {
        SDL_Log("ERROR: can't load texture: %s", path.c_str());
    }

    path = "assets/textures/exit_on.png";
    pSurface = IMG_Load(path.c_str());
    if (pSurface) {
        mpOnExitButtonTexture = SDL_CreateTextureFromSurface(mrRenderer.GetRawRenderer(), pSurface);
        SDL_FreeSurface(pSurface);
    }
    else {
        SDL_Log("ERROR: can't load texture: %s", path.c_str());
    }

    path = "assets/textures/records.png";
    pSurface = IMG_Load(path.c_str());
    if (pSurface) {
        mpRecordsButtonTexture = SDL_CreateTextureFromSurface(mrRenderer.GetRawRenderer(), pSurface);
        SDL_FreeSurface(pSurface);
    }
    else {
        SDL_Log("ERROR: can't load texture: %s", path.c_str());
    }

    path = "assets/textures/records_on.png";
    pSurface = IMG_Load(path.c_str());
    if (pSurface) {
        mpOnRecordsButtonTexture = SDL_CreateTextureFromSurface(mrRenderer.GetRawRenderer(), pSurface);
        SDL_FreeSurface(pSurface);
    }
    else {
        SDL_Log("ERROR: can't load texture: %s", path.c_str());
    }
}

StartMenu::~StartMenu() {
    SDL_DestroyTexture(mpPlayButtonTexture);
    SDL_DestroyTexture(mpOnPlayButtonTexture);
    SDL_DestroyTexture(mpRecordsButtonTexture);
    SDL_DestroyTexture(mpOnRecordsButtonTexture);
    SDL_DestroyTexture(mpExitButtonTexture);
    SDL_DestroyTexture(mpOnExitButtonTexture);
}
void StartMenu::Draw() {
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

    static SDL_Texture *pRecordsTexture = nullptr;
    if (gMousePosition.first - mRecordsButtonHitBox.x >= 0 &&
        gMousePosition.first - mRecordsButtonHitBox.x <= mRecordsButtonHitBox.w &&
        gMousePosition.second - mRecordsButtonHitBox.y >= 0 &&
        gMousePosition.second - mRecordsButtonHitBox.y <= mRecordsButtonHitBox.h) {

        pRecordsTexture = mpOnRecordsButtonTexture;
    }
    else {
        pRecordsTexture = mpRecordsButtonTexture;
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

    SDL_RenderCopy(mrRenderer.GetRawRenderer(), pPlayTexture, NULL, &mPlayButtonHitBox);
    SDL_RenderCopy(mrRenderer.GetRawRenderer(), pRecordsTexture, NULL, &mRecordsButtonHitBox);
    SDL_RenderCopy(mrRenderer.GetRawRenderer(), pExitTexture, NULL, &mExitButtonHitBox);
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
    else if (gLeftMouseClickPosition.second.first - mExitButtonHitBox.x >= 0 &&
            gLeftMouseClickPosition.second.first - mExitButtonHitBox.x <= mExitButtonHitBox.w &&
            gLeftMouseClickPosition.second.second - mExitButtonHitBox.y >= 0 &&
            gLeftMouseClickPosition.second.second - mExitButtonHitBox.y <= mExitButtonHitBox.h) {

        clickedButton = StartMenuButton::ExitButton;
    }
    else if (gLeftMouseClickPosition.second.first - mRecordsButtonHitBox.x >= 0 &&
             gLeftMouseClickPosition.second.first - mRecordsButtonHitBox.x <= mRecordsButtonHitBox.w &&
             gLeftMouseClickPosition.second.second - mRecordsButtonHitBox.y >= 0 &&
             gLeftMouseClickPosition.second.second - mRecordsButtonHitBox.y <= mRecordsButtonHitBox.h) {

        clickedButton = StartMenuButton::RecordsButton;
    }
    gLeftMouseClickPosition.first = false;
    return clickedButton;
}