#include "SimplePlatform.h"

SimplePlatform::SimplePlatform(int x, int y) {
    mHitBox.x = x;
    mHitBox.y = y;
    mHitBox.h = WINDOW_HEIGHT * 0.03;
    mHitBox.w = WINDOW_WIDTH * 0.18;

    mSolid = true;
}

SimplePlatform::~SimplePlatform() {

}

void SimplePlatform::Draw(Renderer &renderer) {
    SDL_SetRenderDrawColor(renderer.GetRawRenderer(), 0, 255, 0, 255);
    SDL_RenderFillRect(renderer.GetRawRenderer(), &mHitBox);
}
