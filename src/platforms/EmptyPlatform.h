#ifndef DOODLE_JUMP_EMPTYPLATFORM_H
#define DOODLE_JUMP_EMPTYPLATFORM_H

#include "Platform.h"

class EmptyPlatform : public Platform
{
public:
    EmptyPlatform(int x, int y, Renderer &renderer);
    virtual ~EmptyPlatform(){};

    bool CollisionCallback(bool isCollided) override;
};

#endif // DOODLE_JUMP_EMPTYPLATFORM_H
