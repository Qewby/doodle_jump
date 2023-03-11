#include "MovingPlatform.h"

int MovingPlatform::sPlatformSpeed = 0;

MovingPlatform::MovingPlatform(int x, int y, Renderer &renderer) : Platform(x, y, renderer, "assets/textures/moving_platform.png")
{
    mIsGoingRight = x % 2;
}

bool MovingPlatform::CollisionCallback(bool isCollided)
{
    if (mHitBox.x + mHitBox.w >= WINDOW_WIDTH || mHitBox.x <= 0)
    {
        mIsGoingRight = !mIsGoingRight;
    }
    if (mIsGoingRight)
    {
        mHitBox.x += sPlatformSpeed;
    }
    else
    {
        mHitBox.x -= sPlatformSpeed;
    }
    return isCollided;
}

void MovingPlatform::SetSpeed(int speed)
{
    sPlatformSpeed = speed;
}
