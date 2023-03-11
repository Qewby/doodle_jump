#include "SimplePlatform.h"

SimplePlatform::SimplePlatform(int x, int y, Renderer &renderer) : Platform(x, y, renderer, "assets/textures/simple_platform.png")
{
}

bool SimplePlatform::CollisionCallback(bool isCollided)
{
    return isCollided;
}
