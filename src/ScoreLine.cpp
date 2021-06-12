#include "ScoreLine.h"

ScoreLine::ScoreLine(Renderer& renderer) : Drawable(renderer) {
    mLineHitBox.x = 0;
    mLineHitBox.y = 0;
    mLineHitBox.w = WINDOW_WIDTH;
    mLineHitBox.h = WINDOW_HEIGHT * 0.035;

    mpFont = TTF_OpenFont("assets/fonts/font.ttf", 80);

    mTextHitBox.h = mLineHitBox.h;
    mTextHitBox.w = mLineHitBox.h * 0.4 * gcMaxScoreLength;
    mTextHitBox.x = mLineHitBox.h / 2;
    mTextHitBox.y = 0;
}

ScoreLine::~ScoreLine() {
    SDL_DestroyTexture(mpTexture);
    SDL_FreeSurface(mpSurface);
    TTF_CloseFont(mpFont);
}

void ScoreLine::Draw() {
    SDL_SetRenderDrawColor(mrRenderer.GetRawRenderer(), 255, 255, 255, 255);
    SDL_RenderFillRect(mrRenderer.GetRawRenderer(), &mLineHitBox);

    std::string scoreText = std::to_string(SCORE);
    int emptySize = gcMaxScoreLength - scoreText.length();
    for (int i = 0; i < emptySize; i++) {
        scoreText += " ";
    }
    mpSurface = TTF_RenderText_Solid(mpFont, scoreText.c_str(), {0, 0, 0});
    mpTexture = SDL_CreateTextureFromSurface(mrRenderer.GetRawRenderer(), mpSurface);
    SDL_RenderCopy(mrRenderer.GetRawRenderer(), mpTexture, NULL, &mTextHitBox);
    SDL_DestroyTexture(mpTexture);
    SDL_FreeSurface(mpSurface);
}

void ScoreLine::LoadTextures() {

}

void ScoreLine::DestroyTextures() {

}
