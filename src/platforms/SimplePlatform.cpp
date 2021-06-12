#include "SimplePlatform.h"

SDL_Texture *SimplePlatform::spPlatformTexture = nullptr;

SimplePlatform::SimplePlatform(int x, int y, Renderer& renderer) : Platform(x, y, renderer) {
    mVisible = true;
}

SimplePlatform::~SimplePlatform() {

}

void SimplePlatform::Draw() {
    if (SimplePlatform::spPlatformTexture == nullptr) {
        SDL_Surface *pSurface = IMG_Load("assets/textures/simple_platform.png");
        if (pSurface) {
            spPlatformTexture = SDL_CreateTextureFromSurface(mrRenderer.GetRawRenderer(), pSurface);
            SDL_FreeSurface(pSurface);
        }
    }
    SDL_RenderCopy(mrRenderer.GetRawRenderer(), spPlatformTexture, NULL, &mHitBox);
}

bool SimplePlatform::CollisionCallback(bool isCollided) {
    return isCollided;
}
