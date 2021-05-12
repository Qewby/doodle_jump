#include "Doodle.h"

Doodle::Doodle(int windowWidth, int windowHeight) {
    mHitBox.h = windowHeight * 0.07;
    mHitBox.w = mHitBox.h / 3 * 2;
    mHitBox.x = (windowWidth - mHitBox.w) / 2;
    mHitBox.y = windowHeight - 200;
}

Doodle::~Doodle() {

}

void Doodle::Draw(Renderer &renderer) {
    SDL_SetRenderDrawColor(renderer.GetRawRenderer(), 255, 255, 255, 255);
    SDL_RenderFillRect(renderer.GetRawRenderer(), &mHitBox);
}

SDL_Rect& Doodle::GetHitBox() {
    return mHitBox;
}