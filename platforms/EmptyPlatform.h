#ifndef DOODLE_JUMP_EMPTYPLATFORM_H
#define DOODLE_JUMP_EMPTYPLATFORM_H

#include "Platform.h"

class EmptyPlatform : public Platform {
public:
    EmptyPlatform(int x, int y);
    ~EmptyPlatform();

    bool CollisionCallback(bool isCollided) override;
    void Draw(Renderer &renderer) override;
};


#endif //DOODLE_JUMP_EMPTYPLATFORM_H