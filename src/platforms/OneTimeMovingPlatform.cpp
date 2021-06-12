#include "OneTimeMovingPlatform.h"

OneTimeMovingPlatform::OneTimeMovingPlatform(int x, int y, Renderer& renderer) : MovingPlatform(x, y, renderer) {

}

OneTimeMovingPlatform::~OneTimeMovingPlatform() {

}

void OneTimeMovingPlatform::Draw() {
    if (OneTimePlatform::spPlatformTexture == nullptr) {
        SDL_Surface *pSurface = IMG_Load("assets/textures/one_time_platform.png");
        if (pSurface) {
            OneTimePlatform::spPlatformTexture = SDL_CreateTextureFromSurface(mrRenderer.GetRawRenderer(), pSurface);
            SDL_FreeSurface(pSurface);
        }
    }
    SDL_RenderCopy(mrRenderer.GetRawRenderer(), OneTimePlatform::spPlatformTexture, NULL, &mHitBox);
}

bool OneTimeMovingPlatform::CollisionCallback(bool isCollided) {
    MovingPlatform::CollisionCallback(isCollided);
    if (isCollided) {
        mVisible = false;
    }
    return isCollided;
}