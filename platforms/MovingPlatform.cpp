#include "MovingPlatform.h"

SDL_Texture *MovingPlatform::spPlatformTexture = nullptr;
int MovingPlatform::sPlatformSpeed = 0;

MovingPlatform::MovingPlatform(int x, int y) : Platform(x, y) {
    mVisible = true;
    mIsGoingRight = x % 2;
}

MovingPlatform::~MovingPlatform() {

}

void MovingPlatform::Draw(Renderer &renderer) {
    if (MovingPlatform::spPlatformTexture == nullptr) {
        SDL_Surface *pSurface = IMG_Load("assets/textures/moving_platform.png");
        if (pSurface) {
            spPlatformTexture = SDL_CreateTextureFromSurface(renderer.GetRawRenderer(), pSurface);
            SDL_FreeSurface(pSurface);
        }
    }
    SDL_RenderCopy(renderer.GetRawRenderer(), spPlatformTexture, NULL, &mHitBox);
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
