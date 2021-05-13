#include "SimplePlatform.h"

SimplePlatform::SimplePlatform(int x, int y) : Platform(x, y) {
    mVisible = true;
}

SimplePlatform::~SimplePlatform() {

}


void SimplePlatform::Draw(Renderer &renderer) {
    SDL_SetRenderDrawColor(renderer.GetRawRenderer(), 0, 255, 0, 255);
    SDL_RenderFillRect(renderer.GetRawRenderer(), &mHitBox);
}

bool SimplePlatform::CollisionCallback(bool isCollided) {
    return true;
}
