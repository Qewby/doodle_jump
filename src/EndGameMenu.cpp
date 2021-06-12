#include "EndGameMenu.h"

EndGameMenu::EndGameMenu(Renderer& renderer) : Drawable(renderer) {
    const int indent = 5;
    mScoreLabelHitBox.w = mRecordLabelHitBox.w = WINDOW_WIDTH / 4;
    mScoreLabelHitBox.h = mRecordLabelHitBox.h = mScoreLabelHitBox.w / 2.5;
    mScoreHitBox.h = mRecordHitBox.h = mScoreLabelHitBox.h * 2 / 3;
    mScoreHitBox.w = mRecordHitBox.w = mScoreHitBox.h * 0.4 * gcMaxScoreLength;

    mPlayAgainButtonHitBox.w = mMenuButtonHitBox.w = WINDOW_WIDTH / 2;
    mPlayAgainButtonHitBox.h = mMenuButtonHitBox.h = mPlayAgainButtonHitBox.w / 2.5;

    mScoreLabelHitBox.x = mRecordLabelHitBox.x =
            mPlayAgainButtonHitBox.x = mMenuButtonHitBox.x = (WINDOW_WIDTH - mPlayAgainButtonHitBox.w) / 2;
    mScoreHitBox.x = mRecordHitBox.x = mScoreLabelHitBox.x + mScoreLabelHitBox.w + indent;

    mScoreLabelHitBox.y = (WINDOW_HEIGHT - (2 * (mPlayAgainButtonHitBox.h + mScoreLabelHitBox.h) +
            3 * indent)) / 2;
    mScoreHitBox.y = mScoreLabelHitBox.y + mScoreLabelHitBox.h / 4;
    mRecordLabelHitBox.y = mScoreLabelHitBox.y + mScoreLabelHitBox.h + indent;
    mRecordHitBox.y = mRecordLabelHitBox.y + mRecordLabelHitBox.h / 4;
    mPlayAgainButtonHitBox.y = mRecordLabelHitBox.y + mRecordLabelHitBox.h + indent;
    mMenuButtonHitBox.y = mPlayAgainButtonHitBox.y + mPlayAgainButtonHitBox.h + indent;

    mpPlayAgainButtonTexture = nullptr;
    mpOnPlayAgainButtonTexture = nullptr;
    mpMenuButtonTexture = nullptr;
    mpOnMenuButtonTexture = nullptr;

    mpScoreLabelTexture = nullptr;
    mpScoreTexture = nullptr;
    mpRecordLabelTexture = nullptr;
    mpRecordTexture = nullptr;

    SDL_Surface *pSurface;
    std::string path;

    path = "assets/fonts/font.ttf";
    mpFont = TTF_OpenFont(path.c_str(), 200);
    if (!mpFont) {
        SDL_Log("ERROR: can't load font");
    }

    path = "assets/textures/play_again.png";
    pSurface = IMG_Load(path.c_str());
    if (pSurface) {
        mpPlayAgainButtonTexture = SDL_CreateTextureFromSurface(mrRenderer.GetRawRenderer(), pSurface);
        SDL_FreeSurface(pSurface);
    }
    else {
        SDL_Log("ERROR: can't load texture: %s", path.c_str());
    }

    path = "assets/textures/play_again_on.png";
    pSurface = IMG_Load(path.c_str());
    if (pSurface) {
        mpOnPlayAgainButtonTexture = SDL_CreateTextureFromSurface(mrRenderer.GetRawRenderer(), pSurface);
        SDL_FreeSurface(pSurface);
    }
    else {
        SDL_Log("ERROR: can't load texture: %s", path.c_str());
    }

    path = "assets/textures/menu.png";
    pSurface = IMG_Load(path.c_str());
    if (pSurface) {
        mpMenuButtonTexture = SDL_CreateTextureFromSurface(mrRenderer.GetRawRenderer(), pSurface);
        SDL_FreeSurface(pSurface);
    }
    else {
        SDL_Log("ERROR: can't load texture: %s", path.c_str());
    }

    path = "assets/textures/menu_on.png";
    pSurface = IMG_Load(path.c_str());
    if (pSurface) {
        mpOnMenuButtonTexture = SDL_CreateTextureFromSurface(mrRenderer.GetRawRenderer(), pSurface);
        SDL_FreeSurface(pSurface);
    }
    else {
        SDL_Log("ERROR: can't load texture: %s", path.c_str());
    }

    path = "assets/textures/score_label.png";
    pSurface = IMG_Load(path.c_str());
    if (pSurface) {
        mpScoreLabelTexture = SDL_CreateTextureFromSurface(mrRenderer.GetRawRenderer(), pSurface);
        SDL_FreeSurface(pSurface);
    }
    else {
        SDL_Log("ERROR: can't load texture: %s", path.c_str());
    }

    path = "assets/textures/record_label.png";
    pSurface = IMG_Load(path.c_str());
    if (pSurface) {
        mpRecordLabelTexture = SDL_CreateTextureFromSurface(mrRenderer.GetRawRenderer(), pSurface);
        SDL_FreeSurface(pSurface);
    }
    else {
        SDL_Log("ERROR: can't load texture: %s", path.c_str());
    }
    Update();
}

EndGameMenu::~EndGameMenu() {
    SDL_DestroyTexture(mpPlayAgainButtonTexture);
    SDL_DestroyTexture(mpOnPlayAgainButtonTexture);
    SDL_DestroyTexture(mpMenuButtonTexture);
    SDL_DestroyTexture(mpOnMenuButtonTexture);

    SDL_DestroyTexture(mpScoreLabelTexture);
    SDL_DestroyTexture(mpScoreTexture);
    SDL_DestroyTexture(mpRecordLabelTexture);
    SDL_DestroyTexture(mpRecordTexture);

    TTF_CloseFont(mpFont);
}
void EndGameMenu::Draw() {
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

    SDL_RenderCopy(mrRenderer.GetRawRenderer(), pPlayAgainTexture, NULL, &mPlayAgainButtonHitBox);
    SDL_RenderCopy(mrRenderer.GetRawRenderer(), pMenuTexture, NULL, &mMenuButtonHitBox);
    SDL_RenderCopy(mrRenderer.GetRawRenderer(), mpScoreLabelTexture, NULL, &mScoreLabelHitBox);
    SDL_RenderCopy(mrRenderer.GetRawRenderer(), mpRecordLabelTexture, NULL, &mRecordLabelHitBox);
    SDL_RenderCopy(mrRenderer.GetRawRenderer(), mpScoreTexture, NULL, &mScoreHitBox);
    SDL_RenderCopy(mrRenderer.GetRawRenderer(), mpRecordTexture, NULL, &mRecordHitBox);
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


void EndGameMenu::Update() {
    SDL_Surface *pSurface;

    mScoreText = std::to_string(SCORE);
    int emptySize = gcMaxScoreLength - mScoreText.length();
    for (int i = 0; i < emptySize; i++) {
        mScoreText += " ";
    }
    pSurface = TTF_RenderText_Solid(mpFont, mScoreText.c_str(), {0, 0, 0});
    if (pSurface) {
        mpScoreTexture = SDL_CreateTextureFromSurface(mrRenderer.GetRawRenderer(), pSurface);
        SDL_FreeSurface(pSurface);
    }
    else {
        SDL_Log("ERROR: can't make score texture");
    }

    mRecordText = std::to_string(RECORD);
    emptySize = gcMaxScoreLength - mRecordText.length();
    for (int i = 0; i < emptySize; i++) {
        mRecordText += " ";
    }
    pSurface = TTF_RenderText_Solid(mpFont, mRecordText.c_str(), {0, 0, 0});
    if (pSurface) {
        mpRecordTexture = SDL_CreateTextureFromSurface(mrRenderer.GetRawRenderer(), pSurface);
        SDL_FreeSurface(pSurface);
    }
    else {
        SDL_Log("ERROR: can't make record texture");
    }
}
