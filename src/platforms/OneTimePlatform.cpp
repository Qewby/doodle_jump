#include "OneTimePlatform.h"

SDL_Texture *OneTimePlatform::spPlatformTexture = nullptr;

OneTimePlatform::OneTimePlatform(int x, int y, Renderer& renderer) : Platform(x, y, renderer) {
    mVisible = true;
}

OneTimePlatform::~OneTimePlatform() {

}

void OneTimePlatform::Draw() {
    if (OneTimePlatform::spPlatformTexture == nullptr) {
        SDL_Surface *pSurface = IMG_Load("assets/textures/one_time_platform.png");
        if (pSurface) {
            spPlatformTexture = SDL_CreateTextureFromSurface(mrRenderer.GetRawRenderer(), pSurface);
            SDL_FreeSurface(pSurface);
        }
    }
    SDL_RenderCopy(mrRenderer.GetRawRenderer(), spPlatformTexture, NULL, &mHitBox);
}

bool OneTimePlatform::CollisionCallback(bool isCollided) {
    if(isCollided) {
        mVisible = false;
    }
    return isCollided;
}
