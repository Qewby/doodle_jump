#ifndef DOODLE_JUMP_ONETIMEPLATFORM_H
#define DOODLE_JUMP_ONETIMEPLATFORM_H

#include "Platform.h"

class OneTimePlatform : public Platform{
public:
    OneTimePlatform(int x, int y);
    virtual ~OneTimePlatform();

    bool CollisionCallback(bool isCollided) override;
    void Draw(Renderer &renderer) override;

    static SDL_Texture *spPlatformTexture;
};


#endif //DOODLE_JUMP_ONETIMEPLATFORM_H
