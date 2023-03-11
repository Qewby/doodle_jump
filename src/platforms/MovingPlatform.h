#ifndef DOODLE_JUMP_MOVINGPLATFORM_H
#define DOODLE_JUMP_MOVINGPLATFORM_H

#include "Platform.h"

class MovingPlatform : public virtual Platform
{
public:
    MovingPlatform(int x, int y, Renderer &renderer);
    virtual ~MovingPlatform(){};

    virtual bool CollisionCallback(bool isCollided) override;

    static void SetSpeed(int speed);

private:
    static int sPlatformSpeed;
    bool mIsGoingRight;
};

#endif // DOODLE_JUMP_MOVINGPLATFORM_H
