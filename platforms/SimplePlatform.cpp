#include "SimplePlatform.h"

SDL_Texture *SimplePlatform::spPlatformTexture = nullptr;

SimplePlatform::SimplePlatform(int x, int y) : Platform(x, y) {
    mVisible = true;
}

SimplePlatform::~SimplePlatform() {

}

void SimplePlatform::Draw(Renderer &renderer) {
    if (SimplePlatform::spPlatformTexture == nullptr) {
        SDL_Surface *pSurface = IMG_Load("simple_platform.png");
        if (pSurface) {
            spPlatformTexture = SDL_CreateTextureFromSurface(renderer.GetRawRenderer(), pSurface);
            SDL_FreeSurface(pSurface);
        }
    }
    SDL_RenderCopy(renderer.GetRawRenderer(), spPlatformTexture, NULL, &mHitBox);
}

bool SimplePlatform::CollisionCallback(bool isCollided) {
    return true;
}
