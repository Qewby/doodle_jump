#include "MovingPlatform.h"

SDL_Texture *MovingPlatform::spPlatformTexture = nullptr;
int MovingPlatform::sPlatformSpeed = 0;

MovingPlatform::MovingPlatform(int x, int y, Renderer& renderer) : Platform(x, y, renderer) {
    mVisible = true;
    mIsGoingRight = x % 2;

    if (MovingPlatform::spPlatformTexture == nullptr) {
        std::string path = "assets/textures/moving_platform.png";
        SDL_Surface *pSurface = IMG_Load(path.c_str());
        if (pSurface) {
            spPlatformTexture = SDL_CreateTextureFromSurface(mrRenderer.GetRawRenderer(), pSurface);
            SDL_FreeSurface(pSurface);
        }
        else {
            SDL_Log("can't load image %s", path.c_str());
        }
    }
}

MovingPlatform::~MovingPlatform() {

}

void MovingPlatform::Draw() {
    SDL_RenderCopy(mrRenderer.GetRawRenderer(), spPlatformTexture, NULL, &mHitBox);
}

bool MovingPlatform::CollisionCallback(bool isCollided) {
    if (mHitBox.x + mHitBox.w >= WINDOW_WIDTH || mHitBox.x <= 0) {
        mIsGoingRight = !mIsGoingRight;
    }
    if (mIsGoingRight) {
        mHitBox.x += sPlatformSpeed;
    }
    else {
        mHitBox.x -= sPlatformSpeed;
    }
    return isCollided;
}

void MovingPlatform::SetSpeed(int speed) {
    sPlatformSpeed = speed;
}
