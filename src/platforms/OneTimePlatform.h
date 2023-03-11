#ifndef DOODLE_JUMP_ONETIMEPLATFORM_H
#define DOODLE_JUMP_ONETIMEPLATFORM_H

#include "Platform.h"

class OneTimePlatform : public virtual Platform
{
public:
    OneTimePlatform(int x, int y, Renderer &renderer);
    virtual ~OneTimePlatform(){};

    bool CollisionCallback(bool isCollided) override;
};

#endif // DOODLE_JUMP_ONETIMEPLATFORM_H
