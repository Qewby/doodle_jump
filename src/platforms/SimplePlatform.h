#ifndef DOODLE_JUMP_SIMPLEPLATFORM_H
#define DOODLE_JUMP_SIMPLEPLATFORM_H

#include "Platform.h"

class SimplePlatform : public Platform
{
public:
    SimplePlatform(int x, int y, Renderer &renderer);
    virtual ~SimplePlatform(){};

    bool CollisionCallback(bool isCollided) override;
};

#endif // DOODLE_JUMP_SIMPLEPLATFORM_H
