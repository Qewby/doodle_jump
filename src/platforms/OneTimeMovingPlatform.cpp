#include "OneTimeMovingPlatform.h"

OneTimeMovingPlatform::OneTimeMovingPlatform(int x, int y, Renderer &renderer) : Platform(x, y, renderer, "assets/textures/one_time_platform.png"),
                                                                                 MovingPlatform(x, y, renderer),
                                                                                 OneTimePlatform(x, y, renderer)
{
}

bool OneTimeMovingPlatform::CollisionCallback(bool isCollided)
{
    return MovingPlatform::CollisionCallback(isCollided) && OneTimePlatform::CollisionCallback(isCollided);
}