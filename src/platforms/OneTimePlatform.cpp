#include "OneTimePlatform.h"

OneTimePlatform::OneTimePlatform(int x, int y, Renderer &renderer) : Platform(x, y, renderer, "assets/textures/one_time_platform.png")
{
}

bool OneTimePlatform::CollisionCallback(bool isCollided)
{
    if (isCollided)
    {
        mVisible = false;
    }
    return isCollided;
}
