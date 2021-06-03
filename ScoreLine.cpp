#include "ScoreLine.h"

ScoreLine::ScoreLine() {
    mLineHitBox.x = 0;
    mLineHitBox.y = 0;
    mLineHitBox.w = WINDOW_WIDTH;
    mLineHitBox.h = WINDOW_HEIGHT * 0.035;

    mpFont = TTF_OpenFont("font.ttf", 80);

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

void ScoreLine::Draw(Renderer &renderer) {
    SDL_SetRenderDrawColor(renderer.GetRawRenderer(), 255, 255, 255, 255);
    SDL_RenderFillRect(renderer.GetRawRenderer(), &mLineHitBox);

    std::string scoreText = std::to_string(SCORE);
    int emptySize = gcMaxScoreLength - scoreText.length();
    for (int i = 0; i < emptySize; i++) {
        scoreText += " ";
    }
    mpSurface = TTF_RenderText_Solid(mpFont, scoreText.c_str(), {0, 0, 0});
    mpTexture = SDL_CreateTextureFromSurface(renderer.GetRawRenderer(), mpSurface);
    SDL_RenderCopy(renderer.GetRawRenderer(), mpTexture, NULL, &mTextHitBox);
}
