#ifndef DOODLE_JUMP_SIMPLEPLATFORM_H
#define DOODLE_JUMP_SIMPLEPLATFORM_H

#include "Platform.h"
#include "../Renderer.h"

class SimplePlatform : public Platform {
public:
    SimplePlatform(int x, int y);
    ~SimplePlatform();

    bool CollisionCallback(bool isCollided) override;
    void Draw(Renderer &renderer) override;
};


#endif //DOODLE_JUMP_SIMPLEPLATFORM_H
