#ifndef DOODLE_JUMP_ONETIMEMOVINGPLATFORM_H
#define DOODLE_JUMP_ONETIMEMOVINGPLATFORM_H

#include "MovingPlatform.h"
#include "OneTimePlatform.h"

class OneTimeMovingPlatform : public OneTimePlatform, MovingPlatform
{
public:
    OneTimeMovingPlatform(int x, int y, Renderer &renderer);
    virtual ~OneTimeMovingPlatform(){};

    bool CollisionCallback(bool isCollided) override;
};

#endif // DOODLE_JUMP_ONETIMEMOVINGPLATFORM_H
